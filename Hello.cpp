#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello "+name+", it is nice to meet you.\n";
    return 0;
}
