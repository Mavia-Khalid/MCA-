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

};
void Array::display()
{
    for(int i=0;i<size;i++)
    {
        cout << " " << arr[i];
    }
}
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
        arr[i]=arr[i-1];
    }
    arr[index]=x;
    size++;
}
void store(Array &a , int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        if(j%2==0)
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
    Array a(100);
    store(a , 40);
    a.display();
    return 0;
}
