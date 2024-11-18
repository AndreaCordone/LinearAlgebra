#include<iostream> 
#include<string>
#include<iomanip>

#include "matrix.hpp"
#include "LinAlg.hpp" 


int main () {


Matrix a(4,4,0); 
Matrix b(4,4,0); 

a(0,0) = 2; 
a(0,1) = 12; 
a(1,0) = 4; 
a(1,1) = 1.2;
a(2,0) = 0.5; 
a(2,2) = 0.3; 


b(0,0) = 2;
b(0,1) = 3.5; 
b(1,0) = 1.333; 
b(1,1) = 5.37; 
b(2,0) = 0.6; 
b(2,2) = 0.34; 




Matrix d(4,4,0); 
Matrix k(4,4,0);

d = mat_multiply(a,b);  
k = StrassenAlgorithm(a,b); 

// uncomment to set the number of decimal places to format the ouput
std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 

std::cout<<a; 

std::cout<<b; 



std::cout<<d; 



std::cout<<k<<std::endl; 


return 0; 



}
