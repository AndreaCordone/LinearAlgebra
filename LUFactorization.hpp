
#ifndef LUFACT_HPP
#define LUFACT_HPP

#include "Matrix.hpp"

namespace LUFactorization {


std::vector<Matrix> LUPQ (const Matrix &A); 

std::vector<Matrix> LUP  (const Matrix &A); 


} // namespace MatrixFactorization

#endif