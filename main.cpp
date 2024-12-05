#include<iostream> 
#include<string>
#include<iomanip>

#include<chrono> 


#include "matrix.hpp"
#include "LinAlg.hpp" 


int main () {



    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

int dim = 16; 
std::vector<int>  stop = {64,16,4}; 


Matrix a(dim,dim,0,100,"rand");
Matrix b(dim,dim,0,100,"rand"); 

// uncomment to set the number of decimal places to format the ouput
std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 

std::cout<<std::endl; 

std::cout<<a<<std::endl; 

std::cout<<b<<std::endl; 

Matrix c(dim,dim,0); 


Matrix d(dim,dim,0); 



std::cout<<"StopTime"<<","<<"MM"<<","<<"SA"<<std::endl;  

for (auto i = stop.begin(); i != stop.end();  ++i) {


 auto t1 = high_resolution_clock::now();

c = MatrixMultiplication(a,b);  

 auto t2 = high_resolution_clock::now();


 auto ms_int_MM = duration_cast<milliseconds>(t2 - t1);



 auto t3 = high_resolution_clock::now();

 d = StrassenAlgorithm(a,b,*i); 

 auto t4 = high_resolution_clock::now();

 auto ms_int_SA = duration_cast<milliseconds>(t4 - t3);

 
std::cout<<*i<<","<<ms_int_MM.count()<<","<<ms_int_SA.count()<<std::endl; 

}

std::cout<<std::endl; 

std::cout<<c<<std::endl; 

std::cout<<d<<std::endl; 





// uncomment to set the number of decimal places to format the ouput
//std::cout<<std::fixed; 
//std::cout<<std::setprecision(5); 
 






return 0; 



}
