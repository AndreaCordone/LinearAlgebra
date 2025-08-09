#define THROW_RUNTIME(msg)                                                     \
  throw std::runtime_error(std::string(msg) + " at " + __FILE__ +              \
                           " at Line:" + std::to_string(__LINE__))

#include "CHFactorization.hpp"
#include "SpecialMatrix.hpp"
#include "MatrixOperation.hpp"
#include "MatrixArithmetic.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>

namespace CHFactorization{

Matrix CHK(const Matrix &A) {

  Matrix RES(A);

  size_t n = A.RowSize();
  size_t m = A.ColSize();

  // Check if Matrix is square
  if (n != m)
    THROW_RUNTIME("The matrix is not square");

  RES(0, 0) = std::sqrt(A(0, 0));

  for (size_t j = 1; j < m; ++j) {
    for (size_t i = 0; i < j; ++i)

    {
      if (RES(j, j) <= 0)
        THROW_RUNTIME("Pivotal element is null or negative");

      for (size_t k = 0; k < i; ++k) {
        RES(i, j) -= RES(k, i) * RES(k, j);
      }

      RES(i, j) = RES(i, j) / RES(i, i);
    }

    for (size_t k = 0; k < j; ++k) {

      RES(j, j) -= (RES(k, j) * RES(k, j));
    }
    RES(j, j) = std::sqrt(RES(j, j));
  }

  return RES;
}

}
