#include <iostream>
#include <cstdlib>
using namespace std;
//to make it more accurate, change the floats to doubles and integers to longs?

float f(float x)
{
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

float mc(int a, int b, int n) //a=left bound, b=right bound, n=number of x-values you want to generate (suggested: 1000000)
{
    float x, total; //defines x and total
    total = 0; //intializing total
    for (int i = 0; i < n; i++) //for loop that repeats, adding one more point to the plot each time it runs through
    {
        x = (b-a)*((float)rand() / (float)(RAND_MAX)) +a; //generates a random x-value from a to b for x coordinate
        total += (b-a) * f(x);
    }
    return total/n;
}

int main()
{
    int a, b;
    cout << "Please enter a range [a,b] where a and b are integers \n";
    cin >> a >> b;
    int n;
    cout << "Enter an integer n, number of points to be generated (suggested: n=1,000,000 for accuracy, but any n>=100,000 will get close) \n";
    cin >> n;
    cout << "The approximate area is: " << mc(a, b, n);
}
