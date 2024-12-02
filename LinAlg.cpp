#include "LinAlg.hpp"
#include "matrix.hpp"



// Matrix Multiplication 
// C [NxP] = A*B [NxM * MxP]
// A = left most matrix
// B = right most matrix

Matrix MatrixMultiplication (Matrix & A, Matrix & B)

{
    if (A.col_size() != B.row_size()) throw std::invalid_argument("First matrix col number must match Second matrix row number"); 
    
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
// * need to evaluate rectangular matrxi
// * include the check for matrix with different dimension
//  
Matrix StrassenAlgorithm (Matrix A, Matrix B)
{

    size_t N = A.row_size(); 
    size_t K = A.col_size();   // common A and B dimension A.col_size() == B.row_size(); 
    size_t M = B.col_size();  
    
    Matrix C(N,M,0); 

    if ((A.size()==1) & (B.size()==1))
    {
        C(0,0) = A(0,0)*B(0,0);
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

        P1 = StrassenAlgorithm(A11,B12-B22); 
        P2 = StrassenAlgorithm(A11+A12,B22); 
        P3 = StrassenAlgorithm(A21+A22,B11); 
        P4 = StrassenAlgorithm(A22,B21-B11);
        P5 = StrassenAlgorithm(A11+A22,B11+B22); 
        P6 = StrassenAlgorithm(A12-A22,B21+B22);
        P7 = StrassenAlgorithm(A11-A21,B11+B12); 

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
}
