#include "LinAlg.hpp"
#include "matrix.hpp"



// Matrix Multiplication 
// C [NxP] = A*B [NxM * MxP]
// A = left most matrix
// B = right most matrix



Matrix MatrixMultiplication::SMM (Matrix & A, Matrix & B)

{
    if (A.col_size() != B.row_size()) throw std::invalid_argument("matrix A col number must match B matrix row number"); 
    
    size_t N = A.row_size();
    size_t K = A.col_size();   // common A and B dimension A.get_col == B.get_row(); 
    size_t M = B.col_size();  

    Matrix C(N,M,0);  // Output matrix C = A*B
       
        for (size_t i=0; i <N; ++i)
            for (size_t j=0; j<M; ++j)
                for (size_t k=0; k<K; ++k)
                    C(i,j) += A(i,k)*B(k,j);
    return C; 
}



// Up to know only working for:
// *  square matrices 
// *  matrix dimension 2^(N)
// for all the other case (rectangular matrix, matrix dimension not power of 2) consider to use the padding 
// padding can be achieved through append_row / append_col by appending zeros to get a square matrix with dimension power of 2 
Matrix MatrixMultiplication::SAM (Matrix A, Matrix B, int stop )
{
    
    size_t N = A.row_size(); 
    size_t K = A.col_size();
    size_t L = B.row_size();    // common A and B dimension A.col_size() == B.row_size(); 
    size_t M = B.col_size();  
    
    // check data consistency 
    if (N != K || L!=M )    throw std::invalid_argument ("input matrix should be square, for rectangular matrix consider padding"); 
    if (K != L)             throw std::invalid_argument ("matrix A col number must match B matrix row number");     
    if ((N & (N-1)) != 0 )  throw std::invalid_argument ("matrix dimension must be a power of 2"); 
   

    Matrix C(N,M,0); 


    if ((A.size()==stop) && (B.size()==stop))
    {
        

        if (stop != A.size() ) throw std::invalid_argument ("the stopping criteria do not match matrix size"); 
        C = SMM(A,B);     
        
        return C; 
    }
    
    else
    {
        Matrix C11(N/2,M/2,0);   
        Matrix C12(N/2,M/2,0); 
        Matrix C21(N/2,M/2,0);
        Matrix C22(N/2,M/2,0);  

        Matrix P1(N,K,0); 
        Matrix P2(N,K,0);
        Matrix P3(N,K,0);
        Matrix P4(N,K,0);
        Matrix P5(N,K,0);
        Matrix P6(N,K,0); 
        Matrix P7(N,K,0); 
    
        Matrix A11(N/2,K/2,0);  
        Matrix A12(N/2,K/2,0); 
        Matrix A21(N/2,K/2,0); 
        Matrix A22(N/2,K/2,0); 
 
        Matrix B11(N/2,K/2,0);  
        Matrix B12(N/2,K/2,0);  
        Matrix B21(N/2,K/2,0);  
        Matrix B22(N/2,K/2,0); 

        A11 = A(0,N/2-1,0,K/2-1);
        A12 = A(0,N/2-1,K/2,K-1);
        A21 = A(N/2,N-1,0,K/2-1);
        A22 = A(N/2,N-1,K/2,K-1);

        B11 = B(0,K/2-1,0,M/2-1); 
        B12 = B(0,K/2-1,M/2,M-1);
        B21 = B(K/2,K-1,0,M/2-1);
        B22 = B(K/2,K-1,M/2,M-1);

        P1 = SAM(A11,B12-B22,stop); 
        P2 = SAM(A11+A12,B22,stop); 
        P3 = SAM(A21+A22,B11,stop); 
        P4 = SAM(A22,B21-B11,stop);
        P5 = SAM(A11+A22,B11+B22,stop); 
        P6 = SAM(A12-A22,B21+B22,stop);
        P7 = SAM(A11-A21,B11+B12,stop); 

        C11 = P5+P4-P2+P6; 
        C12 = P1+P2; 
        C21 = P3+P4; 
        C22 = P1+P5-P3-P7;
    
        C.assign(C11,0,N/2-1,0,M/2-1);  
        C.assign(C12,0,N/2-1,M/2,M-1);  
        C.assign(C21,N/2,N-1,0,M/2-1); 
        C.assign(C22,N/2,N-1,M/2,M-1);  

        return  C; 
    }


//MatrixMultipliaction::SCM(Matrix A, double)

}

