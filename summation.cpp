#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    for (int i = 0; i<=20; i=i+1){
        sum = sum + i;
        //cout << i;
        //cout << sum;
    }
    cout << sum << "\n";
    return 0;
}
