#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Finds the mean of the x coordinates and the y coordinates and outputs it to the screen.
int main(){
    double sumx = 0;
    double sumy = 0;
    string xx, yy;
    ifstream inputFile;
    int numofpairs;
    inputFile.open("data1.txt");
    if (!inputFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    inputFile >> numofpairs;
    inputFile >> xx >> yy;
    //cout << numofpairs;
    //cout << xx << " " << yy << "\n";
    double x, y;
    for(int i = 0; i<numofpairs; i++){
        inputFile >> x >> y;
        //cout << x << "\n";
        //cout << y << "\n";
        sumx = sumx + x;
        sumy = sumy + y;
    }
    //cout << sumx << " " << sumy << "\n";
    cout << "The mean of all the x coordinates is: " <<(double)sumx/(double)numofpairs << "\n";
    cout << "The mean of all the y coordinates is: " <<(double)sumy/(double)numofpairs << "\n";
    inputFile.close();
}
