#include "Matrix.hpp"

#include <iomanip>

#define THROW_RUNTIME(msg)                                                     \
  throw std::runtime_error(std::string(msg) + " at " + __FILE__ + ":" +       \
                            std::to_string(__LINE__))

//  CLASS CONSTRUCTOR: takes initilizer list and row, col dimension
Matrix::Matrix(std::initializer_list<std::vector<double>> const &init_list,
               size_t i, size_t j)
    : mRow{i}, mCol{j} {

  for (auto i : init_list)
    mData.insert(mData.end(), i.begin(), i.end());
}

// CLASS CONSTRUCTOR takes row, col dimension and fill the matrix with val
Matrix::Matrix(size_t i, size_t j, double val)
    : mRow{i}, mCol{j}, mData(i * j, val) {}

// Get Element
double Matrix::operator()(size_t i, size_t j) const {
  return mData.at(i * mCol + j);
}

// Modify Element
double &Matrix::operator()(size_t i, size_t j) {
  return mData.at(i * mCol + j);
}

// Get Row Size
size_t Matrix::RowSize() const { return mRow; }

// Get Col size
size_t Matrix::ColSize() const { return mCol; }

// Get Upper Triangular
Matrix Matrix::UT() const {
  bool IsSquare = mRow == mCol;

  if (!IsSquare) {
    throw std::runtime_error("Matrxi is not square");
  }

  Matrix UT(mRow, mCol, 0.0);

  for (size_t i = 0; i < UT.RowSize(); ++i) {
    for (size_t j = 0; j < UT.ColSize(); ++j)

    {
      if (j >= i)
        UT(i, j) = this->operator()(i, j);
    }
  }

  return UT;
}


// Get Lower Triangular
Matrix Matrix::LT() const {

bool IsSquare = mRow == mCol;

  if (!IsSquare) {
    throw std::runtime_error("Matrxi is not square");
  }

  Matrix LT(mRow, mCol, 0.0);

  for (size_t i = 0; i < LT.RowSize(); ++i) {
    for (size_t j = 0; j < LT.ColSize(); ++j)

    {
      if (j <= i)
        LT(i, j) = this->operator()(i, j);
    }
  }

  return LT;


}



// Extract Sub Matrix 

Matrix Matrix::Slice (size_t i, size_t j, size_t n, size_t m) const {


  if (i > j || n >m ) THROW_RUNTIME ("Indices are not consistent"); 

  if (m> this->RowSize() || j > this->ColSize()) THROW_RUNTIME ("Indices are out of matrix dimension"); 

  size_t RowDim = j - i + 1; 
  size_t ColDim = m - n + 1; 
  Matrix RES(RowDim, ColDim, 0.0); 

  for (size_t RowIdx = i; RowIdx <= j; ++RowIdx){
    for (size_t ColIdx = n; ColIdx <= m; ++ColIdx){

      RES(RowIdx-i,ColIdx-n) = this->operator()(RowIdx,ColIdx); 
    
    }
  }

return RES; 

}




std::ostream &operator<<(std::ostream &os, const Matrix &M) {

  std::cout << std::fixed << std::setprecision(6);
  size_t RowCount = 0;
  os << std::endl;
  for (auto k : M.mData)

  {
    RowCount += 1;
    os << k << " ";
    if (RowCount == M.mCol) {
      RowCount = 0;
      os << std::endl;
    }
  }
  return os;
}
