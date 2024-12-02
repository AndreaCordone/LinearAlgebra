#include "matrix.hpp"

// Construction of a matrix filled with a single value given by the user
Matrix::Matrix(size_t row_, size_t col_, double val): row(row_), col(col_), data(col_*row_,val) {}


// Construction of a matrix filled with random number

// trovare un modo piu elegante di dare una string per specificare rand.
Matrix::Matrix(size_t row_, size_t col_, std::string rand): row(row_), col(col_), data(col_*row_)
{

    std::random_device rd; 
    std::mt19937 gen(rd()); 

    std::uniform_real_distribution<> val (0,100); 

    for (size_t i = 0; i<this->row*this->col; ++i) {this->data.at(i) = val(gen);}

}

// Get access of matrix element.
// This methods return a reference allowing to change the matrix element
double & Matrix::operator () (size_t i, size_t j) 
{

    if (j >= this->col_size() || i>= this->row_size()) throw std::invalid_argument("index out of range"); 

    return data.at(col*i + j);

}


// Return a copy of the selected row as a std::vector
std::vector<double>  Matrix::get_row (size_t row_number)
{

std::vector<double> res; 
    
for (size_t j = 0; j<col; ++j) {res.push_back(data.at(row_number*col + j));}
    
return res; 

}

// Return a copy of the selected column as a std::vector
std::vector<double> Matrix::get_col (size_t col_number) 
{

std::vector<double> res; 

res.reserve(row);  
    
for (size_t i = 0; i<row; ++i) {res.push_back(data.at(i*col + col_number));}

return res; 

}




// This method takes a matrix B (dim(B) < dim(A)) ans substitute it inside matrix A in the position specified with row_begin/row_end/col_begin/col_end

void Matrix::assign(Matrix B, size_t row_begin, size_t row_end, size_t col_begin, size_t col_end)
{
    // exception: if matrix B dimension is grater than matrix A
    if (B.size() >= this->size()) throw std::invalid_argument("matrix to be inserted exceeds destination matrix dimension"); 
    
    // exception if row_begin > row_end or col_begin > col_end
    if (row_begin>row_end || col_begin>col_end) throw std::invalid_argument("row/col begin must be less equal than row/col end");
    
    for (size_t i = 0;  i <=row_end-row_begin;  ++i){
        
        for(size_t j = 0;  j <=col_end-col_begin; ++j){

            // I am using the operator overloading I defined above. Should I use the classic C++ access to make it faster?  
            this->operator()(i+row_begin,j+col_begin) = B(i,j); 
        }
    }
}




// Return sub matrix from the original as a copy (NOT a reference to a sub-matrix) 
Matrix  Matrix::operator () (size_t row_begin, size_t row_end, size_t col_begin, size_t col_end)
{


    // exception if row_begin > row_end or col_begin > col_end
    if (row_begin>row_end || col_begin>col_end) throw std::invalid_argument("start row/col must be less than end col/row"); 
    
    // exception if index is out of matrix dimension
    if (row_end>=this->row || col_end>=this->col) throw std::invalid_argument("Matrix::operator()::row/col index out of range"); 

    size_t row_size = row_end - row_begin + 1;  // because row_begin start from 0
    size_t col_size = col_end - col_begin + 1;  // because col_begin start form 0
    
    Matrix res(row_size, col_size,0);           // create the result matrix

    for (size_t i=0; i<row_size; ++i){

        for (size_t j=0; j<col_size; ++j){

                res(i,j) = this->operator()(i+row_begin,j+col_begin);
        }
    }           
    
    return res; 
}


// Ostream operator overloading
std::ostream & operator << (std::ostream &os, const Matrix & A)
{  
    os<<std::endl;  // Print a new line at the beginning
    
    // print matrix element without any formatting
    for (size_t i = 0; i<A.row*A.col; ++i){  
            
        if (i%A.col == 0 && i > 0) {os<<std::endl; };  // print a new line once the row ends
        os<<" "<< A.data[i]<<" ";
        
    }
    
    // Print a new line at the end
    os<<std::endl; 
    return os; 
}


// Matrix Sum
Matrix Matrix::operator + (Matrix B)
{
    if (this->size() != B.size()) throw std::invalid_argument("Matrices size do not match"); 

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



// Insertion of row
void Matrix::append_row(std::vector<double> Row)
{

    if (Row.size() != this->col) throw std::invalid_argument("row to append does not match matrix col dimension"); 
 
    data.insert(data.end(), Row.begin(), Row.end());

    // devo fare upate della dimensioni di row
    this->row+=1; 
     
}


void Matrix::append_col (std::vector<double> Col)
{

    // check input data consistency 
    if (Col.size() != this->row) throw std::invalid_argument("column to append does not match matrix row dimension"); 
    
    // Iterator of the matrix data (should I write a specific iterator for may matrix class)
    std::vector<double>::iterator insert_pos = data.begin(); 

    for (size_t i = 0; i < Col.size(); ++i)
    {

        // advance the position of insert_pos 
        std::advance(insert_pos,(col+1)*i+col); 

        // insert the value in data at position insert_pos
        this->data.insert(insert_pos, Col[i]); 

        // insert_pos must be re-defined since the dimension of the vector was changed by insert()
        insert_pos = data.begin(); 

    }

    // update matrix dimension
    this->col+=1; 

}    
