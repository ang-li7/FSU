#include <iostream>
#include <iterator>
#include <array>
#include <vector>
using namespace std;

void printMatrix(double *p, int N, int M){
    for(int j = 0; j<N; j++){
        for(int i = 0; i<M; i++){
            cout << p[i+j*M] << " ";
        }
        cout << "\n";
    }
}

int main(){
    double *p;
    double A[][3] = {{1,2,3, 4},{1,2,3, 4},{1,2,3, 4}, {1, 2, 3, 4}};
    p = &(A[0][0]);
    int N = sizeof(A)/sizeof(A[0]);
    int M = sizeof(A[0])/sizeof(A[0][0]);
    //cout << N << "\n";
    //cout << M << "\n";
    printMatrix(p, N, M);
    return 0;
}
