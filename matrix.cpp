#include "matrix.hpp"

// Construction of a matrix filled with a single value
Matrix::Matrix(size_t row_, size_t col_, double val): row(row_), col(col_), data(col_*row_,val) {}

// Element access
double & Matrix::operator () (size_t i, size_t j) {

    if (j >= this->col_size() || i>= this->row_size()) throw std::invalid_argument("index out of range"); 

    return data.at(col*i + j);

}


// Get row
std::vector<double>  Matrix::get_row (size_t row_number)
{
std::vector<double> res; 
    
for (size_t j = 0; j<col; ++j) res.push_back(data.at(row_number*col + j)); 
    
return res; 
}

// Get col
std::vector<double> Matrix::get_col (size_t col_number) 
{
std::vector<double> res; 
res.reserve(row);  
    for (size_t i = 0; i<row; ++i)
    {      
        res.push_back(data.at(i*col + col_number));  
    }
return res; 
}




// Matrix assign
void Matrix::assign(Matrix B, size_t row_begin, size_t row_end, size_t col_begin, size_t col_end)
{
    if (B.size() >= this->size()) throw std::invalid_argument("insertion matrix dimension exceeds destination matrix dimension"); 
    if (row_begin>row_end || col_begin>col_end) throw std::invalid_argument("row/col begin must be less equal than row/col end");
    
    for (size_t i = 0;  i <=row_end-row_begin;  ++i)
        for(size_t j = 0;  j <=col_end-col_begin; ++j)
            this->operator()(i+row_begin,j+col_begin) = B(i,j); 
}




// Get sub-matrix
Matrix  Matrix::operator () (size_t row_begin, size_t row_end, size_t col_begin, size_t col_end)
{


    if (row_begin>row_end || col_begin>col_end) throw std::invalid_argument("start row/col must be less than end col/row"); 
    if (row_end>=this->row || col_end>=this->col) throw std::invalid_argument("row/col index out of range"); 

    size_t row_size = row_end - row_begin + 1; // because row_begin start from 0
    size_t col_size = col_end - col_begin + 1; // because col_begin start form 0
    
    Matrix res(row_size, col_size,0); 

    for (size_t i=0; i<row_size; ++i)
        for (size_t j=0; j<col_size; ++j)
            {
                res(i,j) = this->operator()(i+row_begin,j+col_begin);
            }            
    return res; 
}


// Ostream operatore overloading
std::ostream & operator << (std::ostream &os, const Matrix & A)
{  
    os<<std::endl; 
    for (size_t i = 0; i<A.row*A.col; ++i)
        {  
            if (i%A.col == 0 && i > 0) {os<<std::endl; };  
            os<<" "<< A.data[i]<<" ";
        }
    os<<std::endl; 
    return os; 
}


// Matrix Sum
Matrix Matrix::operator + (Matrix B)
{
    if (this->size() != B.size()) throw std::invalid_argument("Matrices size do not macth"); 

    Matrix res(row,col,0); 

    std::transform(this->data.cbegin(), this->data.cend(), B.data.cbegin(), res.data.begin(), std::plus<double>{});  

    return res; 
}

//Matrix Subtraction
Matrix Matrix::operator - (Matrix B) 
{
    if (this->size() != B.size()) throw std::invalid_argument("Matrices size do not macth"); 

    Matrix res(row,col,0); 

    std::transform(this->data.cbegin(), this->data.cend(), B.data.cbegin(), res.data.begin(), std::minus<double>{});  

    return res; 
}


// Change sign
void Matrix::change_sign() {std::transform(this->data.cbegin(), this->data.cend(), this->data.begin(), std::negate<double>{});}

/* Matrix Multiplication
Matrix Matrix::operator * (Matrix B)
{

    if (this->col != B.row) throw std::invalid_argument("Left matrix number of column must be equal to right matrix number of row"); 

    Matrix res (this->row, B.col,0); 

    for (size_t i; i<this->row;  ++i) 
        {
        for (size_t j; j<this->col, ++j)
            {
                res(i,j) = std::transfor(this.get_row(i).cbegin(),this.get_row(i).cend(), B.get_col(j).cbegin(), std::multiply<double>{});      
            }
        }

} 
*/
