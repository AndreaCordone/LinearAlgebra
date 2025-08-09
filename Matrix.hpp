#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

/**
 * @class Matrix
 * @brief Construct a matrix of doubles
 *
 */

class Matrix {

public:
  /**
   * @brief  Number of Cols
   */

  size_t mRow;

  /**
   * @brief  Number of Rows
   */
  size_t mCol;

  /**
   * @brief  Vector to store matrix content
   */

  std::vector<double> mData;

  /**
   * @brief  Construct a new Matrix object of dimension i,j filled with a single
   * value
   * @param i Number of rows
   * @param j Number of columns
   * @param val Initial value for all elements
   */

  Matrix(size_t, size_t, double);

  /**
   * @brief Construct a new Matrix object of dimension ixj with initialization
   * list
   * @param i Number of rows
   * @param j Number of columns
   * @param val Initial value for all elements
   */

  Matrix(std::initializer_list<std::vector<double>> const &, size_t, size_t);

  // Get Element
  /**
   * @brief Return a const copy of a the matrix element
   * @param i Row index
   * @param j Col index
   * @return  Return a const copy of teh element in position (i,j)
   */
  double operator()(size_t, size_t) const;

  // Modify Element
  /**
   * @brief Return a reference to a matrix element
   * @param i Row index
   * @param j Col index
   * @return  Return a reference to a matrix element in position (i,j)
   */

  double &operator()(size_t i, size_t j);

  // Get Row size
  /**
   * @brief Return the number of Rows
   */

  size_t RowSize() const;

  // Get Colsize
  /**
   * @brief Return the number of Cols
   */

  size_t ColSize() const;

  // Get Upper TRiabgular
  Matrix UT() const;

  // Extract Lower Triangular
  Matrix LT() const; 


  // Extract SubMatrix

  Matrix Slice (size_t, size_t, size_t, size_t) const; 


  // Ostream overloading
  /**
   * @brief Output stream overloding to print the matrix content.
   * @param os Output stream object reference
   * @param M const matrix refernece
   * @return Output stream object reference
   */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &M);
};

#endif