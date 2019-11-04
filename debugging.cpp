#include <iostream>
#include <string>

using namespace std;

void sort(float x, float y, float z)
{
    if (x < y)
    {
        if (y < z)
        {
            cout << x << " "  << y << " " << z << endl;
        }
        else
        {
            if (x < z)
            {
                cout << x << "  "<< z << " " << y << endl;
            }
            else
            {
                cout << z << " " << x << " " << y << endl;
            }
        }
    }
    else
        if (y > z)
        {
            cout << z << " " << y << " " << x << endl;
        }
        else
        {
            if (z < x)
            {
                cout << y << " " << z << " " << x << endl;
            }
            else
            {
                cout << y << " " << x << " " << z << endl;
            }
        }
}


int main(){
    sort(3, 5, 1);
    return 0;
}

