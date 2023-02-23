#include<iostream>
using namespace std;
class Matrix
{
    int** arr;
    int n;
    public:
    Matrix(int order)
    {
        n = order;
        arr = new int*[n];
        for(int i=0; i<n; i++)
        {
            arr[i] = new int[n];
        }
    }
    void Read();
    void PrintLUTM();
    void PrintSM();
    void Multiply(Matrix &B);

};
void Matrix::Read()
{
    cout << "\n\t Enter Array Elements : " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void Matrix::PrintLUTM()
{
    cout << "\n\t Matrix : " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i+j <= n-1)
            {
                cout << " " << arr[i][j];
            }
            else
            {
                cout << " 0";
            }
        }
        cout << endl;
    }
}
void Matrix::PrintSM()
{
    cout << "\n\t Enter Array Elements : " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
}
void Matrix::Multiply(Matrix &B)
{
    if(n != B.n)
    {
        cout << "\n\t Multiplication Not Allowed " << endl;
    }
    Matrix C(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            C.arr[i][j] = 0;
            for(int k=0; k<=(n-1)-max(i,j); k++)
            {
                C.arr[i][j] = C.arr[i][j] + arr[i][k] * B.arr[k][j];
            }
        }
    }
    cout << "\n\t Matrix is : ";
    C.PrintSM();
}
int main()
{
    int order;
    cout << "\n\t Enter Order of A Matrix : "; 
    cin >> order;
    Matrix A(order);
    A.Read();
    A.PrintLUTM();
    cout << " \n\t Enter Order of B Matrix : ";
    cin >> order;
    Matrix B(order);
    B.Read();
    B.PrintLUTM();
    A.Multiply(B);
    cout << endl << endl;
    return 0;
}