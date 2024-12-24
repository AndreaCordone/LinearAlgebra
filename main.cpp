#include<iostream> 
#include<string>
#include<iomanip>

#include<chrono> 


#include "matrix.hpp"
#include "LinAlg.hpp" 


int main () {


Matrix a (4,4,1); 
double c  = -1.5; 


Matrix C (4,4,0); 

// uncomment to set the number of decimal places to format the ouput
std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 


Matrix D (4,4,0); 

D = MatrixMultiplication::SM(a,c); 
 
C = D.Row(0,3,1) + D.Col(3,6,1); 
 
C.assign(D,0,3,0,3); 

std::cout<<a<<std::endl; 
std::cout<<C<<std::endl; 
std::cout<<D<<std::endl; 






/* Iterator 
std::vector<double>::iterator & it = a.ColIteratorBegin(2);  
std::vector<double>::iterator & itend = a.ColIteratorEnd(2); 


//std::cout<<*it<<std::endl;
//std::cout<<*itend<<std::endl;

for (it; it <= itend; a.ColIterAdvance())
{
std::cout<<*it<<std::endl; 
}

*/ 

/*
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;


std::vector<int> matrix_dim = {32,64}; 




// uncomment to set the number of decimal places to format the ouput
std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 

std::cout<<std::endl; 



std::cout<<"Dim"<<","<<"StopTime"<<","<<"MM"<<","<<"SA"<<std::endl;  

for (auto i = matrix_dim.begin(); i != matrix_dim.end();  ++i) {


Matrix a(*i,*i,0,100,"rand");
Matrix b(*i,*i,0,100,"rand"); 




Matrix c(*i,*i,0); 
Matrix d(*i,*i,0); 

int size  = a.size(); 

for (auto j = size/4; j >=2 ;)

{


 auto t1 = high_resolution_clock::now();

c = MatrixMultiplication::SMM(a,b);  

 auto t2 = high_resolution_clock::now();


 auto ms_int_MM = duration_cast<milliseconds>(t2 - t1);



 auto t3 = high_resolution_clock::now();

 d = MatrixMultiplication::SAM(a,b,j); 

 auto t4 = high_resolution_clock::now();

 auto ms_int_SA = duration_cast<milliseconds>(t4 - t3);

 

std::cout<<a.size()<<","<<j<<","<<ms_int_MM.count()<<","<<ms_int_SA.count()<<std::endl; 
j = j/4;  
}

std::cout<<"New run"<<std::endl; 



}

*/



// uncomment to set the number of decimal places to format the ouput
//std::cout<<std::fixed; 
//std::cout<<std::setprecision(5); 
 






return 0; 



}
