#ifndef MY_MATRIX_HPP
#define MY_MATRIX_HPP

#include<iostream>
#include<vector>
#include<algorithm> 
#include<random>

class Matrix {

public:

// CONSTRUCTOR METHODS

    // Construction of a matrix of size rowxcol with a single value
    Matrix (size_t,size_t, double);  

    // Construct a matrix filled with random value
    Matrix (size_t,size_t, std::string); 


// COPY CONSTRUCTOR 

    // UNDER DEFINITION


// FRIENDS

    // Output stream overloading 
    friend std::ostream & operator << (std::ostream &, const Matrix &);  


//ACCESS

    // Access element
    double & operator () (size_t , size_t); 

    // Get row 
    std::vector<double> get_row (size_t); 

    // Get col
    std::vector<double> get_col (size_t); 

    // Get col size
    size_t col_size()   {return col;}

    // Get row size
    size_t row_size()   {return row;}

    // Get matrix size
    size_t size()       {return row*col;}

    // Get sub-matrix
    Matrix  operator () (size_t, size_t, size_t, size_t); 


// MANIPULATION

    // Insert row
    // UNDER CONSTRUCTION

    // Insert col
    // UNDER CONSTRUCTION

    // Insert sub-matrix. 
    // Matrix B to be inserted in matrix A
    // Position where to insert in A given as (start row, end row, start col, end col) 
    void assign(Matrix, size_t, size_t, size_t, size_t);  

    // Append a row at the end of the matrix
    void append_row(std::vector<double>); 

   // Append a column at the end of the matrix
   void append_col(std::vector<double>);  



// MATRIX OPERATION

    // Matrix Sum
    Matrix operator + (Matrix);  
    
    // Matrix Subtraction
    Matrix operator - (Matrix); 

    // Matrix Change Sign
    void change_sign(); 
    
    

private:

    //Row number
    size_t row;  

    //Column number
    size_t col; 

    //Matrix
    std::vector<double> data; 

};



#endif 
