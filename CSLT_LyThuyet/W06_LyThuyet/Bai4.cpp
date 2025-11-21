#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int checkPrime(int n){
    for (int i=2; i <= sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return n > 1;
}

void nhap(istream &in, int a[], int &na){
    while (!in.eof()){
        in >> a[na];
        na++;
    }
}

void xuat(ostream &out, int b[], int nb){
    for (int i=0; i<nb; i++){
        out << b[i] << " ";
    }
}

int main(){
    const char *pathIn = "NUMBER.TXT";
    const char *pathOut = "PRIME.TXT";
    int a[10001], b[10001];
    int na = 0, nb = 0;

    ifstream fIn;
    fIn.open(pathIn);
    if (!fIn.is_open()){
        cout << "Khong the doc file" << endl;
        return 1;
    }
    nhap(fIn, a, na);
    fIn.close();

    for (int i = 0; i < na; i++){
        if (checkPrime(a[i])){
            b[nb] = a[i];
            nb++;
        }
    }

    ofstream fOut;
    fOut.open(pathOut);
    if (!fOut.is_open()){
        cout << "Khong the ghi file" << endl;
        return 1;
    }
    xuat(fOut, b, nb);
    fOut.close();

    return 0;
}