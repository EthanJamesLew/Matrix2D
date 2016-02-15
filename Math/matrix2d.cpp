#ifndef MATRIX2D_CPP
#define MATRIX2D_CPP

#include "matrix2d.h"

                                                
template<typename T>
Matrix2D<T>::Matrix2D(unsigned _rows, unsigned _cols, const T& _initial) {
	mat.resize(_rows);
	for (unsigned i = 0; i<mat.size(); i++) {
		mat[i].resize(_cols, _initial);
	}
	rows = _rows;
	cols = _cols;
}

                                         
template<typename T>
Matrix2D<T>::Matrix2D(const Matrix2D<T>& rhs) {
	mat = rhs.mat;
	rows = rhs.get_rows();
	cols = rhs.get_cols();
}

                                         
template<typename T>
Matrix2D<T>::~Matrix2D() {}

                                               
template<typename T>
Matrix2D<T>& Matrix2D<T>::operator=(const Matrix2D<T>& rhs) {
	if (&rhs == this)
		return *this;

	unsigned new_rows = rhs.get_rows();
	unsigned new_cols = rhs.get_cols();

	mat.resize(new_rows);
	for (unsigned i = 0; i<mat.size(); i++) {
		mat[i].resize(new_cols);
	}

	for (unsigned i = 0; i<new_rows; i++) {
		for (unsigned j = 0; j<new_cols; j++) {
			mat[i][j] = rhs(i, j);
		}
	}
	rows = new_rows;
	cols = new_cols;

	return *this;
}

                                                 
template<typename T>
Matrix2D<T> Matrix2D<T>::operator+(const Matrix2D<T>& rhs) {
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[i][j] + rhs(i, j);
		}
	}

	return result;
}

                                                 
template<typename T>
Matrix2D<T>& Matrix2D<T>::operator+=(const Matrix2D<T>& rhs) {
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			this->mat[i][j] += rhs(i, j);
		}
	}

	return *this;
}

                                                 
template<typename T>
Matrix2D<T> Matrix2D<T>::operator-(const Matrix2D<T>& rhs) {
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[i][j] - rhs(i, j);
		}
	}

	return result;
}

                                                  
template<typename T>
Matrix2D<T>& Matrix2D<T>::operator-=(const Matrix2D<T>& rhs) {
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			this->mat[i][j] -= rhs(i, j);
		}
	}

	return *this;
}

                                                 
template<typename T>
Matrix2D<T> Matrix2D<T>::operator*(const Matrix2D<T>& rhs) {
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			for (unsigned k = 0; k<rows; k++) {
				result(i, j) += this->mat[i][k] * rhs(k, j);
			}
		}
	}

	return result;
}

                                                 
template<typename T>
Matrix2D<T>& Matrix2D<T>::operator*=(const Matrix2D<T>& rhs) {
	Matrix2D result = (*this) * rhs;
	(*this) = result;
	return *this;
}

                                                 
template<typename T>
Matrix2D<T> Matrix2D<T>::transpose() {
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[j][i];
		}
	}

	return result;
}

                                                
template<typename T>
Matrix2D<T> Matrix2D<T>::operator+(const T& rhs) {
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[i][j] + rhs;
		}
	}

	return result;
}

                                                
template<typename T>
Matrix2D<T> Matrix2D<T>::operator-(const T& rhs) {
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[i][j] - rhs;
		}
	}

	return result;
}

                                                
template<typename T>
Matrix2D<T> Matrix2D<T>::operator*(const T& rhs) {
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[i][j] * rhs;
		}
	}

	return result;
}

                                                 
template<typename T>
Matrix2D<T> Matrix2D<T>::operator/(const T& rhs) {
	Matrix2D result(rows, cols, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result(i, j) = this->mat[i][j] / rhs;
		}
	}

	return result;
}

                                                
template<typename T>
std::vector<T> Matrix2D<T>::operator*(const std::vector<T>& rhs) {
	std::vector<T> result(rhs.size(), 0.0);

	for (unsigned i = 0; i<rows; i++) {
		for (unsigned j = 0; j<cols; j++) {
			result[i] = this->mat[i][j] * rhs[j];
		}
	}

	return result;
}

                                                 
template<typename T>
std::vector<T> Matrix2D<T>::diag_vec() {
	std::vector<T> result(rows, 0.0);

	for (unsigned i = 0; i<rows; i++) {
		result[i] = this->mat[i][i];
	}

	return result;
}

                                                  
template<typename T>
T& Matrix2D<T>::operator()(const unsigned& row, const unsigned& col) {
	return this->mat[row][col];
}

                                                  
template<typename T>
const T& Matrix2D<T>::operator()(const unsigned& row, const unsigned& col) const {
	return this->mat[row][col];
}

                                                 
template<typename T>
unsigned Matrix2D<T>::get_rows() const {
	return this->rows;
}

                                                  
template<typename T>
unsigned Matrix2D<T>::get_cols() const {
	return this->cols;
}

#endif