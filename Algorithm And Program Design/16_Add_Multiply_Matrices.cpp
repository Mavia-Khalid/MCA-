#include<iostream>
using namespace std;
void Print_Matrix(int matrix[100][100] , int row, int col);
void Add_Matrix(int mat1[100][100] , int row1, int col1, int mat2[100][100] , int row2 , int col2);
void Multiply_Matrix(int mat1[100][100] , int row1, int col1, int mat2[100][100] , int row2 , int col2);
void Insert_Matrix(int mat[100][100] , int row , int col);
int main()
{
	int mat1[100][100],mat2[100][100],row1,col1,row2,col2;
	cout<<"\t Enter the rows For matrix 1 : ";
	cin>>row1;
	cout<<"\tEnter the columns For matrix 1 : ";
	cin>>col1;
	Insert_Matrix(mat1 , row1 , col1); 

	cout<<"\n\n\t The First Matrix is : ";
	Print_Matrix(mat1,row1,col1);

	cout<<"\t Enter the no. of rows in matrix 2 : ";
	cin>>row2;
	cout<<"\t Enter the no. of columns in matrix 2 : ";
	cin>>col2;
	cout<<"\n\n\t Enter the elements in "<<row2<<" * "<<col2<<" matrix 2 : "<<endl;
	Insert_Matrix(mat2 , row2 , col2);

	cout<<"\n\n\t The Second Matrix is : ";
	Print_Matrix(mat2 , row2 , col2);

	Add_Matrix(mat1, row1, col1, mat2, row2, col2);
	Multiply_Matrix(mat1, row1, col1, mat2, row2, col2);

	system("pause");
	return 0;
}

void Multiply_Matrix(int mat1[100][100], int row1, int col1, int mat2[100][100], int row2, int col2)
{
	int mat[100][100], row=row1, col=col2;
	if(col1 != row2)  // Column of First Matrix and Row of Second Matrix Must be Equal for Multiplication 
	{	
	cout<<"\n\t Multiplication is not possible !!\n";
	}
	else
	{
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col2; j++)
			{	
				for(int k=0; k<col1; k++)
				{
					mat[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}

		cout<<"\n\t Matrix multiplication is : ";
		Print_Matrix(mat , row , col);
	}
}
void Add_Matrix(int mat1[100][100], int row1, int col1, int mat2[100][100], int row2, int col2)
{
	int mat[100][100];
	if(row1!=row2 || col1!=col2)
	{
		cout<<"\n\t Matrix addition is not possible!!\n";
	}
	else
	{
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col1; j++)
			{	
				mat[i][j]=mat1[i][j]+mat2[i][j];
			}
		}
		cout<<"\n\t Addition of matrix is : ";
		Print_Matrix(mat,row1,col1);
	}
}
void Print_Matrix(int matrix[100][100], int row, int col)
{
	cout<<endl<<endl;
	for(int i=0; i<row; i++)
	{
		cout<<"\t ";
		for(int j=0; j<col; j++)
		{
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void Insert_Matrix(int mat[100][100] , int row , int col)
{
	cout<<"\n\n\t Enter the elements in "<<row<<" * "<<col<<" Matrix : "<<endl;
	for(int i=0; i<row; i++)
	{
		cout<<"\t ";
		for(int j=0; j<col; j++)
		{
			cin>>mat[i][j];
	}
	}
}