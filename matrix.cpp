#include "matrix.hpp"

// CONSTRUCTOR 

// Construction of a matrix filled with a single value given by the user
Matrix::Matrix(int row_, int col_, double val): row(row_), col(col_), data(col_*row_,val) {}


// Construction of a matrix filled with random number
Matrix::Matrix(int row_, int col_, int max_val, int min_val, std::string rand): row(row_), col(col_), data(col_*row_)
{

    std::random_device rd; 
    std::mt19937 gen(rd()); 

    std::uniform_real_distribution<> val (min_val,max_val); 

    for (int i = 0; i<this->row*this->col; ++i) {this->data.at(i) = val(gen);}

}

// COPY CONSTRUCTOR 


Matrix & Matrix::operator = (const Matrix & A) 
{


if (this->row_size() != A.row_size() || this->col_size() != A.col_size()) throw std::invalid_argument("Copy Constructor Error: from object and to object dimension do not agree");  

this->row = A.row_size(); 
this->col = A.col_size(); 
this->data = A.get_data(); 


return *this; 

}



// Get access of matrix element.
// This methods return a reference allowing to change the matrix element
double & Matrix::operator () (int i, int j) 
{

    if (j >= this->col_size() || i>= this->row_size()) throw std::invalid_argument("index out of range"); 

    return data.at(col*i + j);

}


double  Matrix::operator () (int i, int j) const
{

    if (j >= this->col_size() || i>= this->row_size()) throw std::invalid_argument("index out of range"); 

    return data.at(col*i + j);

}




// Return a copy of the selected row as a std::vector
std::vector<double>  Matrix::get_row (int row_number)
{

std::vector<double> res; 
    
for (int j = 0; j<col; ++j) {res.push_back(data.at(row_number*col + j));}
    
return res; 

}

// Return a copy of the selected column as a std::vector
std::vector<double> Matrix::get_col (int col_number) 
{

std::vector<double> res; 

res.reserve(row);  
    
for (int i = 0; i<row; ++i) {res.push_back(data.at(i*col + col_number));}

return res; 

}




// This method takes a matrix B (dim(B) < dim(A)) ans substitute it inside matrix A in the position specified with row_begin/row_end/col_begin/col_end

void Matrix::assign(Matrix B, int row_begin, int row_end, int col_begin, int col_end)
{
    // exception: if matrix B dimension is grater than matrix A
    if (B.size() > this->size()) throw std::invalid_argument("matrix to be inserted exceeds destination matrix dimension"); 
    
    if (B.size() != (row_end-row_begin+1)*(col_end-col_begin+1)) throw std::invalid_argument("matrix to be inserted do not match destination dimension"); 
 
    // exception if row_begin > row_end or col_begin > col_end
    if (row_begin>row_end || col_begin>col_end) throw std::invalid_argument("row/col begin must be less equal than row/col end");
    
    for (int i = 0;  i <=row_end-row_begin;  ++i){
        
        for(int j = 0;  j <=col_end-col_begin; ++j){

            // I am using the operator overloading I defined above. Should I use the classic C++ access to make it faster?  
            this->operator()(i+row_begin,j+col_begin) = B(i,j); 
        }
    }
}




// Return sub matrix from the original as a copy (NOT a reference to a sub-matrix) 
const Matrix  Matrix::operator () (int row_begin, int row_end, int col_begin, int col_end) const
{


    // exception if row_begin > row_end or col_begin > col_end
    if (row_begin>row_end || col_begin>col_end) throw std::invalid_argument("start row/col must be less than end col/row"); 
    
    // exception if index is out of matrix dimension
    if (row_end>=this->row || col_end>=this->col) throw std::invalid_argument("Matrix::operator()::row/col index out of range"); 

    int row_size = row_end - row_begin + 1;  // because row_begin start from 0
    int col_size = col_end - col_begin + 1;  // because col_begin start form 0
    
    Matrix res(row_size, col_size,0);           // create the result matrix

    for (int i=0; i<row_size; ++i){

        for (int j=0; j<col_size; ++j){

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
    for (int i = 0; i<A.row*A.col; ++i){  
            
        if (i%A.col == 0 && i > 0) {os<<std::endl; };  // print a new line once the row ends
        os<<" "<< A.data[i]<<" ";
        
    }
    
    // Print a new line at the end
    os<<std::endl; 
    return os; 
}


// Matrix Sum
Matrix Matrix::operator + (const Matrix & B)
{
    if (this->size() != B.size()) throw std::invalid_argument("Matrices size do not match"); 

    Matrix res(row,col,0); 

    std::transform(this->data.cbegin(), this->data.cend(), B.data.cbegin(), res.data.begin(), std::plus<double>{});  

    return res; 
}

//Matrix Subtraction
Matrix Matrix::operator - (const Matrix & B) 
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
    if (Col.size() != this->row) throw std::invalid_argument("Matrix::append_col::column to append does not match matrix row dimension"); 
    
    // Iterator of the matrix data (should I write a specific iterator for may matrix class)
    std::vector<double>::iterator insert_pos = data.begin(); 

    for (int i = 0; i < Col.size(); ++i)
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






Matrix  Matrix::Row (int i, double prod, double sum) 
{

if ( i >= this->row ) throw std::invalid_argument ("Matrix::Row Error: Index exceed row dimension");  

Matrix res = *this; 

for (int j = 0; j < this->col; ++j) res.data[i*this->col + j] =  prod * this->data[i*this->col + j] + sum;


return res;   


}


//insert dimension check
Matrix  Matrix::Col (int j, double prod, double sum) 
{

if ( j >= this->col ) throw std::invalid_argument ("Matrix::Col Error: Index exceed col dimension");  


Matrix res = *this; 

for (int i = 0; i < this->row; ++i) res.data[i*this->col +j] =  prod * this->data[i*this->col + j] + sum;  

return res; 

}






// Tentativo di implementare uno pseudo iterator per colonne. Probabilmente è meglio scrivere un iteratore da zero.




void Matrix::ColIterAdvance()
{

std::advance(this->ColIterBegin, this->col); 


}


std::vector<double>::iterator & Matrix::ColIteratorBegin(int Column)
{

    this->ColIterBegin = data.begin(); 
    std::advance(this->ColIterBegin, Column); 
    return this->ColIterBegin; 

}

 
std::vector<double>::iterator & Matrix::ColIteratorEnd(int Column)
{

    this->ColIterEnd = this->ColIterBegin; 
    std::advance(this->ColIterEnd, this->col*(this->row-1));
    return this->ColIterEnd; 

} 
