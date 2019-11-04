#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
    //return x*x; //note: the bisection method does not work for x^2
    //return cos(x)*cos(x)-x+6;
    //return log(x)+x*x-3;  //note, log(x) has a domain of (0, infinity), please dont enter a nonpositive number.
    int k = 0;
    int j = 0;
    x = x * 10 - 2;
    k = int(x);
    j = int(x / 2);
    float y = (k - j)*(k-j) - .8;
    if (k % 2 == 0)
        y += (x*x - k*k) + 2 * j*(k - x);
    if (x < 0)
        y = -1 * y - 1.6;
    return y;
}

float fp(float x)
{
    //Write code so that this returns the derivative
    //of f(x);
    return (f(x + 0.01) - f(x))/(0.01);
}
float bisectionMethod(){
    float a, b;
    cout << "Please enter a range [a,b] which contains a root of the function" << endl;
    cin >> a;
    cin >> b;
    while (f(a)*f(b)>0){
        cout << "Error, f(a) and f(b) are the same sign and no root could be detected for function f, please enter a different range [a, b] or change f\n";
        cin >> a;
        cin >> b;
    }
    float hi, low, m;
    if(f(a)>f(b)){
        hi = a;
        low = b;
    }
    else{
        hi = b;
        low = a;
    }
    while(abs(hi-low) > 0.000001){
        m = (hi+low)/2;
        if(f(m) == 0){
            return m;
            break;
        }
        if(f(m)>0){
            hi = m;
        }
        else{
            low = m;
        }
    }
    return m;
}
float newtonianMethod(){
    float x, d;
    bool flag;
    cout << "Please enter an initial point to begin the newtonian method";
    cin >> x;
    d = fp(x);
    //cout << "deriv: " << d << "\n";
    flag = false;
    while (flag == false && abs(f(x)) >= 0.00001){
        x = (d*x - f(x))/d;
        //cout << x << " " << f(x) << "\n";
        if (abs(fp(x)) < 0.0000001){
            flag = true;
            break;
        }
    }
    if(flag == true){
        cout << "Error, the derivative is 0 and newtonian's method will not work";
    }
    return x;
}
float secantMethod(){
    float a, b;
    cout << "Please enter a range [a,b]" << endl;
    cin >> a;
    cin >> b;
    float d, temp;
    while(abs(b-a)>=  0.00001){
        if (abs(f(b)) <=0.000000001){
            return b;
            break;
        }
        else{
            d = (f(a)-f(b))/(a-b);
            temp = (d*b-f(b))/d;
            a = b;
            b = temp;
        }
    }
    return b;
    
    return 0;
}
//Write code in main to run Bisection and or Newton's methods
int main()
{
    float root;
    root = bisectionMethod();
    //root = newtonianMethod();
    //root = secantMethod();
    //cout << "The root of f(x) is " << root << "\n";
    //root = newtonianMethod();
    //root = secantMethod();
    cout << "The root of f(x) is " << root << "\n";
    root = secantMethod();
    cout << "The root of f(x) is " << root << "\n";

    return 0;
}
