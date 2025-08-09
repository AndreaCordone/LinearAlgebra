#define THROW_RUNTIME(msg)                                                     \
  throw std::runtime_errors(std::string(msg) + " at " + __FILE__ + ":" +       \
                            std::to_string(__LINE__))

#include "MatrixArithmetic.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

namespace MatrixArithmetic

{

Matrix Add(const Matrix &A, const Matrix &B) {

  // Check if matrix has same size
  bool condition = A.RowSize() == B.RowSize() && A.ColSize() == B.ColSize();

  // Throw exception if condition is not met
  if (!condition) {
    throw std::runtime_error("Matrix dimension do not match");
  }

  // Declare result matrix
  Matrix RES(A.RowSize(), A.ColSize(), 0.0);

  // Fill result matrix
  std::transform(A.mData.begin(), A.mData.end(), B.mData.begin(),
                 RES.mData.begin(), std::plus<>());

  return RES;
}

Matrix Sub(const Matrix &A, const Matrix &B) {

  // Check if matrix has same size
  bool condition = A.RowSize() == B.RowSize() && A.ColSize() == B.ColSize();

  // Throw exception if condition is not met
  if (!condition) {
    throw std::runtime_error("Matrix dimension do not match");
  }

  // Declare result matrix
  Matrix RES(A.RowSize(), A.ColSize(), 0.0);

  // Fill result matrix
  std::transform(A.mData.begin(), A.mData.end(), B.mData.begin(),
                 RES.mData.begin(), std::minus<>());

  return RES;
}

Matrix ElementWiseProduct(const Matrix &A, const Matrix &B) {
  // Check if matrix has same size
  bool condition = A.RowSize() == B.RowSize() && A.ColSize() == B.ColSize();

  // Throw exception if condition is not met
  if (!condition) {
    throw std::runtime_error("Matrix dimension do not match");
  }

  // Declare result matrix
  Matrix RES(A.RowSize(), A.ColSize(), 0.0);

  // Fill result matrix with A + B
  std::transform(A.mData.begin(), A.mData.end(), B.mData.begin(),
                 RES.mData.begin(), std::multiplies<>());

  return RES;
}

Matrix MatrixMultiplication(const Matrix &A, const Matrix &B) {
  // Check if matrix has same size
  bool condition = A.ColSize() == B.RowSize();

  // Throw exception if condition is not met
  if (!condition) {
    throw std::runtime_error("Matrix dimension do not match");
  }

  // Declare result matrix
  Matrix RES(A.RowSize(), B.ColSize(), 0.0);

  
  for (size_t i = 0; i < A.RowSize(); ++i) {
    for (size_t j = 0; j < B.ColSize(); ++j){

      for (size_t k = 0; k < B.ColSize(); ++k){

      RES(i,j) += A(i, k) * B(k, j); 
      }

  
  }
  }
    return RES;

}

Matrix ScalarMultiplication(const Matrix &A, double B) {

  // Declare result matrix
  Matrix RES(A.RowSize(), A.ColSize(), 0.0);

  std::transform(A.mData.begin(), A.mData.end(), RES.mData.begin(),
                 [B](double x) { return B * x; });

  return RES;
}

} // namespace MatrixArithmetic
