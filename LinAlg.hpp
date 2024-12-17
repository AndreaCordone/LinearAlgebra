#ifndef MY_LINALG_HPP
#define MY_LINALG_HPP
#include"matrix.hpp"


// MATRIX BASIC OPERATION 


namespace MatrixMultiplication
{
    // MATRIX MULTIPLICATION 
    
    // Standard out-of-the-book matrix multiplication
    // Simple implementation but slower when matrix dimension increase. 
    Matrix SMM ( Matrix &, Matrix &);  


    //Strassen Algorithm: recursive algorithm faster for matrix with bigger dimension
    // Refer to: https://www.cs.mcgill.ca/~pnguyen/251F09/matrix-mult.pdf 
    Matrix SAM ( Matrix , Matrix, int);  


    //Scalar Matrix Multiplication 
   // Matrix SCM (Matrix, double); 
}


// MATRIX DETERMINANT


// MATRIX FACTORIZATION


// EIGENVALUE


#endif
