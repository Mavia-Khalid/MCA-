#include<iostream>
using namespace std;
class Matrix
{
    int* arr;
    int order;
    public:
    Matrix(int n)
    {
        arr = new int[n*n];
        order = n;
    }
    int map(int i , int j);
    void read();
    void print();
    void add(Matrix &B);
    void Multiply(Matrix &B);
};
int Matrix::map(int i , int j)
{
    return (order*i+j);
}
void Matrix::read()
{
    cout << "\n\t Enter Elemets of Matrix : ";
    for(int i=0; i<order; i++)
    {
        for(int j=0; j<order; j++)
        {
            cin >> arr[map(i,j)];
        }
    }
}
void Matrix::print()
{
    cout << "\n\t Matrix : " << endl;
    for(int i=0; i<order; i++)
    {
        cout << "\t";
        for(int j=0; j<order; j++)
        {
            cout << " " << arr[map(i,j)];
        }
        cout << endl;
    }
    cout << endl;
}
void Matrix::add(Matrix &B)
{
    if(order != B.order)
    {
        cout << "\n\t Addition Not Allowed ";
        return;
    }
    Matrix C(order);
    for(int i=0; i<order; i++)
    {
        for(int j=0; j<order; j++)
        {
            C.arr[map(i,j)] = arr[map(i,j)] + B.arr[map(i,j)];
        }
    }
    cout << "\n\t Matrix After Additon ";
    C.print();
}
void Matrix::Multiply(Matrix &B)
{
    if(order != B.order)
    {
        cout << "\n\t Multiplication Not Allowed ";
        return;
    }
    Matrix C(order);
    for(int i=0; i<order; i++)
    {
        for(int j=0; j<order; j++)
        {
            C.arr[map(i,j)] = 0;
            for(int k=0; k<order; k++)
            {
                C.arr[map(i,j)] = C.arr[map(i,j)] + (arr[map(i,j)] * B.arr[map(i,j)]);
            }
        }
    }
    cout << "\n\t Matrix After Multiplication ";
    C.print();
}
int main()
{
    int order;
    cout << "\n\t Enter Order of A Matrix : ";
    cin >> order;
    Matrix A(order);
    A.read();
    A.print();
    cout << "\n\t Enter Order of B Matrix : ";
    cin >> order;
    Matrix B(order);
    B.read();
    B.print();
    A.add(B);
    A.Multiply(B);
    return 0;
}