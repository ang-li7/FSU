#include <iostream> 
#include <stdlib.h>
#include <random>
using namespace std;

double mc(long n){
    double x, y, total;
    int count = 0;
    for(int i = 0; i<n; i++){
        x = (double)rand() /(double)(RAND_MAX);
        y = (double)rand() /(double) (RAND_MAX);
        total = x*x + y*y;
        if(total < 1){
            count = count + 1;
        }
        
    }
    //cout << count << "\n";
    //cout << n << "\n";
    return (double)count/(double)n;
}

double calcpi(){
    double pi = mc(1000000000)*4;
    return pi;
}

int main(){
    cout << calcpi() <<"\n";
    
    return 0;
}
