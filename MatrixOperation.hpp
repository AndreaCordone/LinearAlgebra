#ifndef MATOP
#define MATOP

#include "Matrix.hpp"

namespace MatrixOperation

{

Matrix Trasnpose(const Matrix &);

Matrix RowPivotMatrix (const Matrix &, size_t, size_t); 

Matrix ColPivotMatrix (const Matrix &, size_t, size_t); 

Matrix PivotRow (const Matrix &, size_t, size_t); 

Matrix PivotCol (const Matrix &, size_t, size_t); 

// Ritorn the max absolute element 
std::tuple <size_t, size_t>  MaxAbsoluteElement (const Matrix &); 

}

#endif