#define THROW_RUNTIME(msg)                                                     \
  throw std::runtime_error(std::string(msg) + " at " + __FILE__ +              \
                           " at Line:" + std::to_string(__LINE__))

#include "LUFactorization.hpp"
#include "SpecialMatrix.hpp"
#include "MatrixOperation.hpp"
#include "MatrixArithmetic.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>

namespace LUFactorization {


std::vector<Matrix> LUP (const Matrix &A){


size_t n = A.RowSize(); 
size_t m = A.ColSize(); 

if (n!=m) THROW_RUNTIME ("The matrix is not square"); 

Matrix P = SpecialMatrix::DiagMatrix(n,m,1.0); 
Matrix L = SpecialMatrix::DiagMatrix(n,m,0.0); 
Matrix U = SpecialMatrix::DiagMatrix(n,m,0.0); 



Matrix M (n,m,0.0); 
Matrix Minv =  SpecialMatrix::DiagMatrix(n,m,1.0);
Matrix Mkinv (n,m,0.0); 
Matrix Mk (n,m,0.0); 


Matrix Eye2(n,m,0.0); 
Eye2 = SpecialMatrix::DiagMatrix(n,m,2.0); // Identity Matrix multiplied by two 2*Eye. This is uses to compuet the invers of Mk

Matrix Ak (n,m,0.0);  // Matrix to be modified at each step during the factorization 
Ak = A; 


for (size_t k = 0; k < n-1; ++k){


  auto [MaxPivotRowIdx, MaxPivotColIdx] = MatrixOperation::MaxAbsoluteElement(Ak.Slice(k,n-1,k,k)); 
  
  
  Mk = SpecialMatrix::DiagMatrix(n,m,1.0); 

 
  Matrix Pk (n,m,0.0);
  Pk = MatrixOperation::RowPivotMatrix(A,k,MaxPivotRowIdx+k); 
  
  Matrix PAk = MatrixArithmetic::MatrixMultiplication(Pk,Ak); 



  // Gauss Matrix Computation on the pivoted matrix PAQk
  for (size_t Idx = k+1; Idx < n; ++Idx){
    Mk(Idx, k) = - PAk(Idx,k)/ PAk(k,k); 
  }

  Mkinv = MatrixArithmetic::Sub(Eye2, Mk); // This is a particular case for inverting a lower triangula matrix.


  Ak = MatrixArithmetic::MatrixMultiplication(Mk,PAk); 
  P = MatrixArithmetic::MatrixMultiplication(Pk,P); 
  Minv = MatrixArithmetic::MatrixMultiplication(Minv,Pk); 
  Minv = MatrixArithmetic::MatrixMultiplication(Minv,Mkinv); 


}


U = Ak.UT(); 
L = MatrixArithmetic::MatrixMultiplication(P,Minv); 

std::vector<Matrix> LUP = {L,U,P}; 

return LUP; 


}





} // Namespace closure