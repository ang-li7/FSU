#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    for(int c = 1; c<11; c++){
        for(int p = 1; p<34; p++){
            int s = (100-(c*10)-(p*3))*2;
            if (c+p+s==100){
                cout << c << "\n";
                cout << p << "\n";
                cout << s << "\n";
            }
        }
    }
}
