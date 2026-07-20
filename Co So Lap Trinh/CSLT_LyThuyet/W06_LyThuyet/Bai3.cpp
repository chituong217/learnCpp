#include <iostream>
#include <fstream>

using namespace std;

void nhap(istream &in, int &m, int &n, int a[][500]){
    in >> m;
    in >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            in >> a[i][j];
        }
    }
}

void reverseMatrix(int a[][500], int m, int n, int b[][500]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            b[i][j] = a[j][n - i - 1];
        }
    }
}

void xuat(ostream &out, int m, int n, int b[][500]){
    out << n << " " << m << endl;
    for (int i=0; i<n; i++){
        for (int j = 0; j < m; j++){
            out << b[i][j] << " ";
        }
        out << endl;
    }
}

int main(){
    const char *pathIn = "MATRIX.TXT";
    const char *pathOut = "OUTPUT.TXT";
    int m, n;
    int a[500][500], b[500][500];

    ifstream fIn;
    fIn.open(pathIn);

    if (!fIn.is_open()){
        cout << "Khong the mo file" << endl;
        return 1;
    }
    nhap(fIn, m, n, a);
    fIn.close();

    reverseMatrix(a, m, n, b);
    
    ofstream fOut;
    fOut.open(pathOut);

    if (!fOut.is_open()){
        cout << "Khong the ghi file" << endl;
        return 1;
    }

    xuat(fOut, m, n, b);

    fOut.close();
    return 0;
}