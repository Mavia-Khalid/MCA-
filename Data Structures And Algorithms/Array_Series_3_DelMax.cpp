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
    // for(int i=size;i>index;i--)
    // {
    //     arr[i]=arr[i-1];
    // }
    arr[index]=x;
    size++;
}
void Array::display()
{
    cout << "\n\t Array : ";
    for(int i=0;i<size;i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n\t Current Size of Array :  " << getsize();
}
int Array::del(int index)
{
    if(index<0||index>size)
    {
        cout << "\n\t Invalid Index ";
        return 0;
    }
    cout << "\n\t Total No of Movements to Delete Element : " << arr[index] << " At Index : " << index;
    int No_Of_Movements = 0;
    for(int i=index; i<size-1; i++)
    {
        arr[i] = arr[i+1];
        No_Of_Movements++;
    }
    size--;
    cout << " = " << No_Of_Movements << endl;
    cout << "\t Size After Deletion : " << getsize();
    return No_Of_Movements;
}
void store(Array &a , int n)                // Generating Repeated Odd Numbers
{
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        if(j%2==0)
        {
            a.insert(j,a.getsize());
        }
        else
        {
            a.insert(j,a.getsize());
            a.insert(j,a.getsize());
        }
    }
}
void Del_Dup_Max_Movements(Array &a , int n)
{
    int Total_No_Of_Movements = 0;
    for(int i=0;i<n;i+=2)
    {
        Total_No_Of_Movements += a.del(i);
    }
    cout << "\n\t Total No of Movements to Delete Duplicates : " << Total_No_Of_Movements << endl;
}

int main()
{
    Array a(1000);
    int size;
    cout<<"\n\t Enter Array Size : ";
    cin>>size;
    store(a , size);
    a.display();
    cout<<endl;
    Del_Dup_Max_Movements(a , size);
    a.display();
    cout<<endl;
    return 0;
}
