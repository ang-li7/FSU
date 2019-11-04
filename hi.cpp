#include <stdio.h>
#include <iostream>
using namespace std;

void sort(int a, int b, int c){
    if (a < b){
        if (b <c){
            cout << a << "\n";
            cout << b << "\n";
            cout << c << "\n";
        }
        else if ( c > a && c < b){
            cout << a << "\n";
            cout << c << "\n";
            cout << b << "\n";
        }
        else{
            cout << c << "\n";
            cout << a << "\n";
            cout << b << "\n";
        }
    }
    else{
        if (c > a){
            cout << b << "\n";
            cout << a << "\n";
            cout << c << "\n";
        }
        else if (c < a && c > b){
            cout << b << "\n";
            cout << c << "\n";
            cout << a << "\n";
        }
        else{
            cout << c << "\n";
            cout << b << "\n";
            cout << a << "\n";
        }
    }
}
int main(){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    sort(a, b, c);
}
