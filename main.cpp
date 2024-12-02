#include<iostream> 
#include<string>
#include<iomanip>

#include "matrix.hpp"
#include "LinAlg.hpp" 


int main () {


std::vector<double> bb (1,99); 
std::vector<double> aa (4,101); 

Matrix a(1,3,"rand");

std::cout<<aa.size(); 
std::cout<<a.col_size(); 

std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 
 std::cout<<a;

 
//Matrix b(8,10,rand); 

a.append_col(bb); 


a.append_row(aa); 

//Matrix d(8,8,0); 
//Matrix k(8,8,0);

//d = MatrixMultiplication(a,b);  
//k = StrassenAlgorithm(a,b); 

// uncomment to set the number of decimal places to format the ouput
std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 

std::cout<<a; 

//std::cout<<b; 



//std::cout<<d; 



//std::cout<<k<<std::endl; 


return 0; 



}
