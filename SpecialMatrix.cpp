#include "SpecialMatrix.hpp"
#include "Matrix.hpp"

namespace SpecialMatrix {

Matrix HilbertMatrix(size_t Row, size_t Col) {
  Matrix RES(Row, Col, 0.0);

  for (size_t i = 0; i < Row; ++i) {
    for (size_t j = 0; j < Col; ++j) {
      RES(i, j) = 1.0 / (i + j + 1);
    }
  }

  return RES;
}


Matrix DiagMatrix (size_t Row,size_t Col,double val){

  Matrix RES(Row,Col,0.0);
  
  for (size_t i = 0; i<RES.RowSize(); ++i){

      RES(i,i) = val; 
    }

return RES; 
  }




} // namespace SpecialMatrix

