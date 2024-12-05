#ifndef MY_LINALG_HPP
#define MY_LINALG_HPP
#include"matrix.hpp"


// MATRIX BASIC OPERATION 

    // MATRIX MULTIPLICATION 
    
    // Standard out-of-the-book matrix multiplication
    // Simple implementation but slower when matrix dimension increase. 
    Matrix MatrixMultiplication ( Matrix &, Matrix &);  


    //Strassen Algorithm: recursive algorithm faster for matrix with bigger dimension
    // Refer to: https://www.cs.mcgill.ca/~pnguyen/251F09/matrix-mult.pdf 
    Matrix StrassenAlgorithm ( Matrix , Matrix, int) ;  



// MATRIX DETERMINANT


// MATRIX FACTORIZATION


// EIGENVALUE


#endif
