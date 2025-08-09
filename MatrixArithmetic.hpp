#ifndef LINALG_HPP
#define LINALG_HPP

#include "Matrix.hpp"

namespace MatrixArithmetic {

Matrix Add(const Matrix &A, const Matrix &B);

Matrix Sub(const Matrix &A, const Matrix &B);

Matrix ScalarMultiplication(const Matrix &A, double scalar);

Matrix MatrixMultiplication(const Matrix &A, const Matrix &B);

} // namespace MatrixArithmetic

#endif