#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double pi = 3.1415926535897;

double calcx(double t){
    return sin(7*pi*t);
    
}
double calcy(double t){
    return cos(5*pi*t);
}
int main(){
    ofstream outFile;
    outFile.open("paradata.txt");
    double x, y;
    for(int i = 0; i<1000; i++){
        double ii = (double)rand() /(double)(RAND_MAX);
        x = calcx(i);
        y = calcy(i);
        //cout << x << "\n";
        //cout << y << "\n";
        outFile << x << " " << y << "\n";
    }
    outFile.close();
    //cout <<"done\n";
    
    return 0;
}
