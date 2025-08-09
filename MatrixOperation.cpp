#define THROW_RUNTIME(msg)                                                     \
  throw std::runtime_error(std::string(msg) + " at " + __FILE__ + ":" +       \
                            std::to_string(__LINE__))

#include "Matrix.hpp"
#include "SpecialMatrix.hpp"

#include <algorithm>
#include <tuple>

namespace MatrixOperation

{

Matrix Trasnpose(const Matrix &A) {

  Matrix RES(A.mCol, A.mRow, 0.0);

  for (size_t i = 0; i < A.mRow; ++i) {
    for (size_t j = 0; j < A.mCol; ++j) {
      RES(i, j) = A(j, i);
    }
  }

  return RES;
}


Matrix RowPivotMatrix (const Matrix & A, size_t i, size_t j)

{

size_t Row = A.RowSize(); 
size_t Col = A.ColSize(); 


Matrix RES = SpecialMatrix::DiagMatrix(Row,Col,1.0); 

// Piovot i <-> j rows
 RES(i,i) = 0.0;
 RES(i,j) = 1.0; 
 RES(j,j) = 0.0; 
 RES(j,i) = 1.0; 


return RES; 
}


Matrix ColPivotMatrix (const Matrix &A, size_t n, size_t m){

size_t Row = A.RowSize(); 
size_t Col = A.ColSize(); 


Matrix RES = SpecialMatrix::DiagMatrix(Row,Col,1.0); 

// Pivit  n <-> m cols

RES(n,n) = 0.0; 
RES(m,n) = 1.0; 
RES(m,m) = 0.0; 
RES(n,m) = 1.0; 

return RES; 

}

std::tuple<size_t,size_t>  MaxAbsoluteElement (const Matrix &A) {

 size_t ColNumber = A.ColSize(); 

  std::vector<double>::const_iterator MaxIt = std::max_element( A.mData.begin(), A.mData.end(),[](double a, double b){return std::abs(a) < std::abs(b); }); 

  if (MaxIt == A.mData.end()) { 
    THROW_RUNTIME ("The Matrxi is empty"); 
  }


  auto LinearIdx = std::distance(A.mData.begin(),MaxIt); 
  
  size_t MaxRowIdx = LinearIdx / ColNumber; 

  size_t MaxColIdx= LinearIdx % ColNumber; 
 
  return std::make_tuple(MaxRowIdx, MaxColIdx);

}


Matrix PivotRow (const Matrix & A, size_t i, size_t j){

  if ( i >= j ) THROW_RUNTIME ("Inverted Row Order");  
  
  Matrix RES(A.RowSize(), A.ColSize(),0.0); 

  RES = A; 
  
  size_t RowOffSet1 = i*A.ColSize(); 
  size_t RowOffSet2 = RowOffSet1 + (j-i) * A.ColSize(); 

  for (size_t idx = RowOffSet1; idx < RowOffSet1 + A.ColSize(); ++idx){
    std::swap(RES.mData[idx], RES.mData[idx + RowOffSet2]); 
  }

return RES; 

}


Matrix PivotCol (const Matrix & A, size_t i, size_t j){

  if ( i >= j ) THROW_RUNTIME ("Inverted Row Order");  
  
  Matrix RES(A.RowSize(), A.ColSize(),0.0); 

  RES = A; 
  
  size_t ColOffSet = (j-i); 
  size_t LastColElem = i + A.ColSize()*( A.RowSize() - 1) ; 

  for (size_t idx = i ; idx <= LastColElem; ){
    std::swap(RES.mData[idx], RES.mData[idx + ColOffSet]); 
    idx += A.RowSize(); 
  }

return RES; 

}


} // namespace MatrixOperation
