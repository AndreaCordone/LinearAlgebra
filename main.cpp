#include<iostream> 
#include<string>
#include<iomanip>

#include<chrono> 


#include "matrix.hpp"
#include "LinAlg.hpp" 


int main () {


Matrix a (4,5,1); 


// uncomment to set the number of decimal places to format the ouput
std::cout<<std::fixed; 
std::cout<<std::setprecision(5); 


Matrix c (4,5,0); 
Matrix d (3,2,1.1); 
 
//c = a.RowByScalar(0,3) + a.ColByScalar(4,6); 
 
//c.assign(d,1,3,2,3); 


//std::cout<<c<<std::endl; 
std::cout<<a<<std::endl; 
std::cout<<a.Row(2,1,2)<<std::endl; 
std::cout<<a.Col(3,5,5)<<std::endl; 



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
