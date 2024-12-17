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
    Matrix (size_t,size_t,int,int, std::string); 


// COPY CONSTRUCTOR 


// DESTRUCTOR

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


/*
class CloumnIterator {

public:

    ColumnIterator () : m_ptr(nullptr) {}
    ColumnIterator (double * ptr) : m_ptr(ptr)  

    double & operator * () const {return *m_ptr; }
    double * operator -> () const {return m_ptr; }


} 
 
*/   

// MANIPULATION



    // Insert sub-matrix. 
    // Matrix B to be inserted in matrix A
    // Position where to insert in A given as (start row, end row, start col, end col) 
    void assign(Matrix, size_t, size_t, size_t, size_t);  

    // Append a row at the end of the matrix
    void append_row(std::vector<double>); 

    // Append a column at the end of the matrix
    void append_col(std::vector<double>);  

    // Row Operation (multiply and sum a scalar)
    Matrix Row (int, double, double); 

    // Col Operation (multiply and sum a scalar)  // sostituiscilo con un metodo ColModify

    Matrix Col (int, double,double); 

 

// MATRIX OPERATION

    // Matrix Sum // Valuatre se inserirli nella liberari LinALg
    Matrix operator + (Matrix);  
    
    // Matrix Subtraction // valutare se inserirli nella libreria Lin alg
    Matrix operator - (Matrix); 


    // Matrix Change Sign
    void change_sign(); 
    


// Iterator -- Still in evluation 
void ColIterAdvance();
std::vector<double>::iterator & ColIteratorBegin(int); 
std::vector<double>::iterator & ColIteratorEnd(int); 


private:

    //Row number // Valutare se chiamare mRow (come da buona norma)
    size_t row;  

    //Column number // valitare se chiamare mCol
    size_t col; 

    //Matrix        // mData
    std::vector<double> data;

    // Col Iterator -- still in progress.
    
    std::vector<double>::iterator ColIterBegin; 
    std::vector<double>::iterator ColIterEnd; 

    


};



#endif 
