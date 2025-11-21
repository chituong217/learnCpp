#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

struct MaTran{
    int rows;
    int cols;
    double data[10][10];
};

bool LoadMaTran(istream &in, MaTran &m){
    if (!(in >> m.rows >> m.cols)){
        return false;
    }
    for (int i=0; i<m.rows; i++){
        for (int j=0; j<m.cols; j++){
            if (!(in >> m.data[i][j])){
                return false;
            }
        }
    }
    return true;
}

void PrintMaTran(ostream &out, const MaTran &m){
    for (int i=0; i < m.rows; i++){
        out << "[ ";
        for (int j=0; j<m.cols; j++){
            out << fixed << setprecision(2) << m.data[i][j] << ' ';
        }
        out << "]" << endl;
    }
}

MaTran TongMaTran(const MaTran &a, const MaTran &b){
    MaTran c = a;
    for (int i=0; i < c.rows; i++){
        for (int j=0; j < c.cols; j++){
            c.data[i][j] += b.data[i][j];
        }
    }
    return c;
}

int main()
{
    const char pathin[] = "C:\\Users\\XAOXIN\\Documents\\c++\\test\\input.txt";
    ifstream fin;
    fin.open(pathin);

    if (!fin.is_open())
    {
        cout << "Khong mo duoc file " << pathin << endl;
        return 1;
    }

    MaTran A, B;
    cout << "Bat dau doc Ma Tran A..." << endl;
    if (!LoadMaTran(fin, A))
    {
        cout << "Doc file loi hoac file rong." << endl;
        fin.close();
        return 1;
    }
    PrintMaTran(cout, A);
    cout << endl;

    cout << "Bat dau doc Ma Tran B..." << endl;
    if (!LoadMaTran(fin, B))
    {
        cout << "Doc file loi, khong co ma tran B." << endl;
        fin.close();
        return 1;
    }
    PrintMaTran(cout, B);
    cout << endl;

    fin.close();

    if (A.rows != B.rows || A.cols != B.cols)
    {
        cout << "Hai ma tran khong cung kich thuoc, khong the cong." << endl;
        return 1;
    }

    cout << "--------------------" << endl;
    cout << "Tong C = A + B:" << endl;
    MaTran C = TongMaTran(A, B);
    PrintMaTran(cout, C);

    return 0;
}