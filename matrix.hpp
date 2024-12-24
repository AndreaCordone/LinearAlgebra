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
    Matrix (int,int, double);  

    // Construct a matrix filled with random value between range 
    Matrix (int,int,int,int, std::string); 


// COPY CONSTRUCTOR 
    
   Matrix & operator =  (const Matrix &); 

// DESTRUCTOR

// FRIENDS

    // Output stream overloading 
    friend std::ostream & operator << (std::ostream &, const Matrix &);  


//ACCESS

    // Access element
    double & operator () (int , int); 

    // Access element
    double  operator ()  (int , int) const ; 


    // Get row 
    std::vector<double> get_row (int); 

    // Get col
    std::vector<double> get_col (int); 

    // Get col size
    int col_size() const   {return col;}

    // Get row size
    int row_size() const  {return row;}

    // Get matrix size
    int size() const    {return row*col;}

    // Access data
    std::vector<double> & get_data () {return this->data;}
    
    // Access data const
    std::vector<double> get_data () const {return this->data;}

    // Get sub-matrix
    const  Matrix  operator () (int, int, int, int) const; 


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
    void assign(Matrix, int, int, int, int);  

    // Append a row at the end of the matrix
    void append_row(std::vector<double>); 

    // Append a column at the end of the matrix
    void append_col(std::vector<double>);  

    // Row Operation (multiply and sum a scalar)
    Matrix Row (int, double, double); 

    // Col Operation (multiply and sum a scalar) 
    Matrix Col (int, double,double); 

 

// MATRIX OPERATION

    // Matrix Sum // Valuatre se inserirli nella liberari LinALg
    Matrix operator + (const Matrix & );  
    
    // Matrix Subtraction // valutare se inserirli nella libreria Lin alg
    Matrix operator - (const Matrix & ); 


    // Matrix Change Sign
    void change_sign(); 
    


// Iterator -- Still in evluation 
void ColIterAdvance();
std::vector<double>::iterator & ColIteratorBegin(int); 
std::vector<double>::iterator & ColIteratorEnd(int); 


private:

    //Row number // Valutare se chiamare mRow (come da buona norma)
    int row;  

    //Column number // valitare se chiamare mCol
    int col; 

    //Matrix        // mData
    std::vector<double> data;

    // Col Iterator -- still in progress.
    
    std::vector<double>::iterator ColIterBegin; 
    std::vector<double>::iterator ColIterEnd; 

    


};



#endif 
