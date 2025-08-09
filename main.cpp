#include "Matrix.hpp"
#include "MatrixArithmetic.hpp"
#include "LUFactorization.hpp"
#include "MatrixOperation.hpp"
#include "SpecialMatrix.hpp"
#include <tuple>

int main () {

  //std::initializer_list<std::vector<double>> c = {{1,2,3},{1,1,1},{4,4,4}};

  //std::cout<<MatrixOperation::PivotCol(M1,1,2)<<std::endl; 


  //Matrix M1 = SpecialMatrix::HilbertMatrix(3, 3);




  Matrix M1 ({{1,2,3},{4,5,6},{7,8,9}},3,3);  

 // Matrix CH(3, 3, 0);

 

  //CH = MatrixFactorization::CHK(M1);

 //  std::cout << M2<< std::endl;


  //Matrix U (3,3,0.0);  


  //Matrix L(3,3,0.0); 
  

  
 

  auto RES = LUFactorization::LUP(M1); 

  std::cout<<"Pivoting"<<std::endl;
  std::cout<<"L Factorization" << RES[0]<<std::endl; 
  std::cout<<"U Factorization" << RES[1]<<std::endl; 
  std::cout<<"P Factorization" << RES[2]<<std::endl; 


  Matrix PA (3,3,0.0); 
  Matrix LU (3,3,0.0); 

  PA = MatrixArithmetic::MatrixMultiplication(RES[2],M1); 
  LU = MatrixArithmetic::MatrixMultiplication(RES[0],RES[1]);

  std::cout<<PA<<std::endl; 
  
  std::cout<<LU<<std::endl;
  
  /*

  auto LUPQ = LUFactorization::LUPQ(M1); 

  std::cout<<"PQpivoting"<<std::endl;
  std::cout<<"L Factorization" << LUPQ[0]<<std::endl; 
  std::cout<<"U Factorization" << LUPQ[1]<<std::endl; 
  std::cout<<"P Factorization" << LUPQ[2]<<std::endl;
  std::cout<<"Q Factorization" << LUPQ[3]<<std::endl;

  Matrix PAQ (3,3,0.0); 
  Matrix LU_ (3,3,0.0); 

  PAQ = MatrixArithmetic::MatrixMultiplication(M1,LUPQ[3]); 
  PAQ = MatrixArithmetic::MatrixMultiplication(LUPQ[2],PAQ); 

  LU_ = MatrixArithmetic::MatrixMultiplication(LUPQ[0],LUPQ[1]);

  std::cout<<PAQ<<std::endl; 
  std::cout<<LU_<<std::endl; 


  */

  return 0; 

}