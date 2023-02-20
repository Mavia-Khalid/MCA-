#include<iostream>
using namespace std;
class Array 
{
    int* arr;
    int length , size;
    public:
    Array(int n)
    {
        arr = new int[n];
        length = n;
        size = 0;
    }
    int getsize();
    void insert(int x , int index);
    void display();
    int del(int index);

};
int Array::getsize()
{
    return size;
}
void Array::insert(int x , int index)
{
    if(index<0||index>size)
    {
        cout<<"\n\t Invalid Index ";
        return;
    }
    if(size==length)
    {
        cout<<"\n\t Array Full ";
        return;
    }
    for(int i=size;i>index;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = x;
    size++;
}
void Array::display()
{
    cout<<"\n\t";
    for(int i=0;i<size;i++)
    {
        cout << " " << arr[i];
    }
}
int Array::del(int index)
{
    if(index<0||index>size)
    {
        cout << "\n\t Invalid Index ";
        return 0;
    }
    for(int i=index; i<size; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
    return 1;
}
void store(Array &a , int n)
{
    for(int i=0;i<n;i++)
    {
        int j = i+1;
        if(j%2 == 0)
        {
            a.insert(j,i);
        }
        else
        {
            a.insert(j,(j-1)/2);
        }
    }
}
int main()
{
    Array a(1000);
    int size;
    cout<<"\n\t Enter Array Size : ";
    cin>>size;
    store(a , size);
    a.display();
    cout << "\n\t Size : " << a.getsize();
    a.del(7);
    cout << endl;
    a.display();
    cout << "\n\t Size : " << a.getsize();
    cout << endl << endl;
    return 0;
}
