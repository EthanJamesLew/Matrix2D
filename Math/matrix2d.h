#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <vector>

template <typename T> class Matrix2D {
 private:
  std::vector<std::vector<T> > mat;
  unsigned rows;
  unsigned cols;

 public:
  Matrix2D(unsigned _rows, unsigned _cols, const T& _initial);
  Matrix2D(const Matrix2D<T>& rhs);
  virtual ~Matrix2D();

                                             
  Matrix2D<T>& operator=(const Matrix2D<T>& rhs);                                              
  Matrix2D<T> operator+(const Matrix2D<T>& rhs);
  Matrix2D<T>& operator+=(const Matrix2D<T>& rhs);
  Matrix2D<T> operator-(const Matrix2D<T>& rhs);
  Matrix2D<T>& operator-=(const Matrix2D<T>& rhs);
  Matrix2D<T> operator*(const Matrix2D<T>& rhs);
  Matrix2D<T>& operator*=(const Matrix2D<T>& rhs);
  Matrix2D<T> transpose();
                                     
  Matrix2D<T> operator+(const T& rhs);
  Matrix2D<T> operator-(const T& rhs);
  Matrix2D<T> operator*(const T& rhs);
  Matrix2D<T> operator/(const T& rhs);

                                           
  std::vector<T> operator*(const std::vector<T>& rhs);
  std::vector<T> diag_vec();

                                             
  T& operator()(const unsigned& row, const unsigned& col);
  const T& operator()(const unsigned& row, const unsigned& col) const;

                                              
  unsigned get_rows() const;
  unsigned get_cols() const;

};

#include "matrix2d.cpp"

#endif