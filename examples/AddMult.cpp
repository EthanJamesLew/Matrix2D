/*This file demonstrates how to add and multiply matrices*/

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include "matrix2d.h"
using namespace std;

void printMatrix(Matrix2D<double> &mat2, string name = "Matrix:");

int main(int argc, char * argv[])
{
	Matrix2D<double> mat(4, 4, 5.0);
	Matrix2D<double> mat1(2, 4, 6.0);

	Matrix2D<double> mat2 = mat * mat1;
	mat2(0, 0) = 323;
	vector<double> vec = {2,3,4,5};

	Matrix2D<double> mat3 = mat + Matrix2D<double>(4,4,3.0);
	//Matrix2D<double> mat4 = mat3.getIdentity();
	printMatrix(mat2, "Matrix Multiplication");
	printMatrix(mat3, "Square Matrix (Mat3)");
	printMatrix(mat3.identity(), "Mat3 Identity:");
	printMatrix(mat3.permutative(), "Mat3 Permutative");
	printMatrix(mat3 * mat3.identity(), "Mat3 * Identity");
	mat3(1, 1) = 9; mat3(1, 0) = 45; mat3(3, 3) = 12;
	printMatrix(mat3, "New Mat3" );
	printMatrix(mat3 * mat3.permutative(), "New Mat3 Permutative");
	printMatrix(mat3 * mat3.identity(), "New Mat3 * Identity");

	cout <<"Mat 3 isSquare: "<<endl<< mat3.isSquare() << endl<<endl;
	cout <<"Mat 2 isSquare: "<<endl<< mat2.isSquare() << endl<<endl;

	return 0;
}

void printMatrix(Matrix2D<double> &mat2, string name = "Matrix:")
{
	cout << name << endl;
	for (int i = 0; i < mat2.get_cols(); i++)
	{
		cout << "| ";
		cout << '\t';
		for (int j = 0; j < mat2.get_rows(); j++)
		{
			cout << mat2(j, i);
			if (j != mat2.get_rows() - 1)
			{
				cout << '\t';
			}
	
		}
		cout << '\t';
		cout << " |";
		cout << endl;
	}
	cout << endl;
	cout.clear();
	return;
}
