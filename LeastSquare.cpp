#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <cmath>
#include <string>

using namespace std;

void printmatrix(vector<vector<double> > A){
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[0].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<double> > matrix(vector<double> x, int k){
    vector<vector<double> > A;
    for(int i = 0; i<x.size(); i++){
        vector<double> aa(k+1);
        for(int j = 0; j<=k; j++){
            aa[j] = pow(x[i], j);
        }
        A.push_back(aa);
    }
    return A;
}
vector<vector<double> > matrixB(vector<double> x){
    vector<vector<double> > B;
    for(int i = 0; i<x.size(); i++){
        vector <double> bb;
        bb.push_back(x[i]);
        B.push_back(bb);
    }
    return B;
}
vector<vector<double> > transpose(vector<vector<double> > x){
    vector<vector<double> > A;
    for(int i = 0; i<x[0].size(); i++){
        vector<double> aa;
        for(int j = 0; j<x.size(); j++){
            aa.push_back(x[j][i]);
        }
        A.push_back(aa);
    }
    return A;
}

vector<vector<double> > multiply(vector<vector<double> > x, vector<vector<double> > y){
    vector<vector<double> > A;
    if(x[0].size() != y.size()){
        cout << "The dimensions dont match (i.e. the number of rows in x dont match with the number of columns in y, therefore you cannot multiply\n";
        return A;
    }
    else{
        for(int i = 0; i<x.size(); i++){
            vector<double> aa;
            for(int j = 0; j<y[0].size(); j++){
                double val = 0;
                for(int k = 0; k<x[0].size(); k++){
                    val = val + x[i][k]*y[k][j];
                }
                aa.push_back(val);
            }
            A.push_back(aa);
        }
        return A;
    }
}

vector<double> gauss(vector< vector<double> > A) {
    for (int i=0; i<A.size(); i++) {
        double num = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<A.size(); k++) {
            if (abs(A[k][i]) > num) {
                num = abs(A[k][i]);
                maxRow = k;
            }
        }
        for (int k=i; k<A.size()+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        for (int k=i+1; k<A.size(); k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<A.size()+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }
    
    vector<double> x(A.size());
    for (int i=A.size()-1; i>=0; i--) {
        x[i] = A[i][A.size()]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][A.size()] -= A[k][i] * x[i];
        }
    }
    return x;
}

void formatequation(vector<double> ans){
    string eq = "y = ";
    for(int i = ans.size()-1; i>=0; i--){
        if(i == 0){
            eq = eq + to_string(ans[i]) + " ";
        }
        else{
            eq = eq + to_string(ans[i])+"x^"+to_string(i)+" + ";
        }
    }
    cout << eq << "\n";
}

int main(){
    //******************************************************************************//
    //reading in the data files //
    cout << "Please enter the file name: (Ex: data1.txt or Datax2.txt)\n";
    string myFileName;
    cin >> myFileName;
    fstream f;
    f.open(myFileName);
    int numOfCoor;
    f >> numOfCoor;
    string xx, yy;
    f >> xx >> yy;
    //cout << numOfCoor << xx << yy;
    vector <double> x(numOfCoor);
    vector <double> y(numOfCoor);
    for(int i = 0; i<numOfCoor; i++){
        f >> x[i] >> y[i];
    }
    //******************************************************************************//
    int k;
    cout << "Please input k, the rank of the curve of best fit: ";
    cin >> k;
    vector<vector<double> > A = matrix(x, k);
    printmatrix(A);
    vector<vector<double> > b = matrixB(y);
    //printmatrix(b);
    vector<vector<double> > At = transpose(A);
    //printmatrix(At);
    //cout << A.size() << " " << A[0].size() << "\n";
    //cout << At.size() << " " << At[0].size() << "\n";
    vector<vector<double> > AtA = multiply(At, A);
    //cout << "AtA: \n";
    //printmatrix(AtA);
    vector<vector<double> > Atb = multiply(At, b);
    //cout << "ATB: \n";
    printmatrix(Atb);
    vector<vector<double> > g;
    for(int i = 0; i<AtA.size(); i++){
        vector <double> gg;
        for(int j = 0; j<AtA[0].size(); j++){
            gg.push_back(AtA[i][j]);
        }
        gg.push_back(Atb[i][0]);
        g.push_back(gg);
    }
    //cout << "g: \n";
    //printmatrix(g);
    vector <double> c = gauss(g);
    formatequation(c);
    
    
    return 0;
    
}
