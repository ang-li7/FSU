#include <iostream>
#include <cmath>
using namespace std;

float f(float x){
    /****
     Please uncomment the function you want to test
     ****/
    
    //return 3*x*x;
    //return cos(x)*cos(x) - x + 6;
    //return log(x) + x*x -3;
    float y = x / 2;
    float z = y - 1;
    while (y - z > .001 || z - y > .001)
    {
        z = y;
        y = z - (z*z - x) / (2 * z);
    }
    return (y - 4.47);
}

float Riemann(int n, float a, float b){
    float ta = a;
    float interval = (float)(b-a)/(float)n;
    float tot = 0;
    for(int i = 0; i<n; i++){
        tot = tot + f(ta)*interval;
        ta = ta + interval;
    }
    return tot;
}
/*********
 We should not let the user choose the width of each rectangle because it the width of a rectangle may not divide the interval evenly.  
 For example, when computing the integral from 0 to 2, if the user chose a rectangle of width of 1.5, we cannot have an integer number of integers.
 **********/

float Trapezoid(int n, float a, float b){
    float ta = a;
    float interval = (float)(b-a)/(float)n;
    float tot = 0;
    for(int i = 0; i<n; i++){
        tot = tot + 0.5*(f(ta)+f(ta+interval))*interval;
        ta = ta + interval;
    }
    return tot;
}

float mc(int n, float a, float b){
    float x, total;
    for(int i = 0; i<n; i++){
        x = ((float)rand()/(float)(RAND_MAX)) * (b-a) + a;
        total = total + f(x);
    }
    return total*(b-a)/n;
}

int main(){
    int n;
    float a, b;
    cout << "Please enter the range to calculate the interval (a, b)\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "Please enter how many intervals you want\n";
    cin >> n;
    cout << "The integral of f(x) with Riemann sum is: " << Riemann(n, a, b) << "\n";
    cout << "The integral of f(x) with Trapezoid sum is: " <<Trapezoid(n, a, b) << "\n";
    cout << "The integral of f(x) with the Monte Carlo is: " << mc(n, a, b) << "\n";
    return 0;
}
