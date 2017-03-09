#include <iostream>
#include <stdio.h>
#include <new>
#include <cmath>

using namespace std;


class Matrix
{
	private:
		int row;
		int col;
		int **array;
	public:
		Matrix(int r,int c)
		{
			row = r;
			col = c;
			array = new int*[row];
			for (int i=0; i <row; i++)
			{
				array[i] = new int [col];
			}
			for(int i = 0; i<row; i++){
				for (int j = 0; j < col; j++)
				{
					array[i][j] = 0;
				}
			}
		}
		Matrix(const Matrix &m)
		{
			row = m.row;
			col = m.col;
			array = new int*[row];
			for (int i =0; i < row; i++)
			{
				for(int j=0; j<col; j++)
				{
					array[i][j] = m.array[i][j];
				}
			}
		}
		~Matrix()
		{
			delete[] array;
		}
		
		void setValue (int r, int c, int e)
		{
			array[r][c] = e;
		}
		
		int getValue (int r, int c)
		{
			return array[r][c];
		}
		//set and get row
		void setRow(int r)
		{
			row = r;
		}
		
		int getRow()
		{
			return row;
		}
		// set and get col
		void setCol(int c)
		{
			col = c;
		}
		
		int getCol()
		{
			return col;
		}
		//overload = operator
		Matrix operator=(const Matrix&m)
		{
			Matrix new_mat (row, col);
			for (int i = 0; i < row; i++)
			{
				for (int j; j < col; j++)
				{
					new_mat.array[i][j] = m.array[i][j];
				}
			}
			return new_mat;
		}
		// overload +  operator
		Matrix operator+(const Matrix& m)
		{
			if(row != m.row || col != m.col)
			{
				cout <<" Matrix sizes do not match " <<endl;
				return (*this);
			}
			Matrix new_mat (row, col);
			for (int i = 0; i < row; i++)
			{
				for (int j; j < col; j++)
				{
					new_mat.array[i][j] = array[i][j] + m.array[i][j];
				}
			}
			return new_mat;
			
		}
		//overload - operator
		Matrix operator-(const Matrix& m)
		{
			if(row != m.row || col != m.col)
			{
				cout <<" Matrix sizes do not match " <<endl;
				return (*this);
			}
			Matrix new_mat (row, col);
			for (int i = 0; i < row; i++)
			{
				for (int j; j < col; j++)
				{
					new_mat.array[i][j] = array[i][j] - m.array[i][j];
				}
			}
			return new_mat;
			
		}
		
		//oveload * operator
		Matrix operator*(const Matrix& m)
		{
			Matrix new_mat(row, col);
			for (int i = 0; i<row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					for (int k =0; k < col; k++)
					{
						new_mat.array[i][j] += array[i][k] * m.array[k][j];
					}
				}
			}
			return new_mat;
		}
	
		//overload << operator
		friend ostream& operator<<(ostream& os, Matrix& m)
		{
			for (int i = 0; i < m.getRow(); i++)
			{
				for (int j = 0; j < m.getCol(); j++)
				{
					os << m.array[i][j];
				}
			}
			os <<endl;
			return os;
		}
		//overload >> operator
		friend istream& operator>>(istream& is, Matrix& m)
		{
			
			for (int i = 0; i < m.getRow(); i++)
			{
				for (int j = 0; j < m.getCol(); j++)
				{
					is >>m.array[i][j];
				}
			}
			return is;
		}
		
		
		
};

int main()
{
	int r = 4;
	int c = 4;
	Matrix matrixA(r,c);
	Matrix matrixB(r,c);
	Matrix matrixC(r,c);

	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			matrixA.setValue(i,j,1);
			matrixB.setValue(i,j,2);
			//matrixC.setValue(i,j,5);
		}
	}

	cout << "matrixA" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixA.getValue(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "matrixB" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixB.getValue(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "matrixC before addition" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixC.getValue(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;

	matrixC = matrixA; // + matrixB;

	cout << "matrixC after addition" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixC.getValue(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}	

