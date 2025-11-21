#include <iostream>
#include <fstream>
#include <cmath> 
#include <iomanip> 

using namespace std;

struct SDaThuc{
    int bac;
    double heso[101];
};

SDaThuc CreateDaThucZero(){
    SDaThuc dt;
    dt.bac = 0;
    dt.heso[0] = 0;
    return dt;
}

void PrintDaThuc (ostream &out, SDaThuc sn){
    out << "P(X) = ";
    bool isFirstTerm = true;

    for (int i = sn.bac; i >= 0; i--){
        if (sn.heso[i] == 0){
            continue;
        }

        if (isFirstTerm == true){
            out << fixed << setprecision(2) << sn.heso[i];
            isFirstTerm = false;
        }
        else{
            if (sn.heso[i] > 0) {
                out << " + " << fixed << setprecision(2) << sn.heso[i];
            } else {
                out << " - " << fixed << setprecision(2) << -sn.heso[i];
            }
        }

        if (i == 1){
            out << "x";
        }
        else if (i > 1){
            out << "x^";
            out << i;
        }
    }

    if (isFirstTerm){
        out << "0.00";
    }
}

SDaThuc LoadDaThuc(istream &in){
    SDaThuc dt;
    in >> dt.bac;
    for (int i=0; i <= dt.bac; i++){
        in >> dt.heso[i];
    }
    return dt;
}

SDaThuc TongDaThuc(const SDaThuc &a, const SDaThuc &b){
    SDaThuc dt;
    if (a.bac > b.bac){
        dt.bac = a.bac;
    }
    else{
        dt.bac = b.bac;
    }

    for (int i = 0; i <= dt.bac; i++) {
        dt.heso[i] = 0.0; 
    }


    for (int i = 0; i <= a.bac; i++) {
        dt.heso[i] += a.heso[i];
    }
    for (int i = 0; i <= b.bac; i++) {
        dt.heso[i] += b.heso[i];
    }

    while (dt.bac > 0 && dt.heso[dt.bac] == 0.0) {
        dt.bac--;
    }

    return dt;
}

double TinhGiaTri(const SDaThuc &p, double x){
    double sum = 0;
    for (int i=0; i <= p.bac; i++){
        sum += p.heso[i] * pow(x, i);
    }
    return sum;
}


int main(){
    const char pathin[] = "input.txt";
    ifstream fin;
    fin.open(pathin);

    if (!fin.is_open())
    {
        cout << "Khong mo duoc file " << pathin << endl;
        return 1;
    }

    double xValue;
    fin >> xValue;
    cout << "Gia tri x se duoc thay vao: " << fixed << setprecision(2) << xValue << endl;
    cout << "--------------------" << endl;

    SDaThuc pTotal = CreateDaThucZero();

    while (!fin.eof())
    {
        SDaThuc p = LoadDaThuc(fin);
        
        if ( fin.fail()) {
             break;
        }

        cout << "Da thuc doc duoc: ";
        PrintDaThuc(cout, p);
        cout << endl;

        pTotal = TongDaThuc(pTotal, p);
    }

    fin.close();

    cout << "--------------------" << endl;
    cout << "Tong cac da thuc: ";
    PrintDaThuc(cout, pTotal);
    cout << endl;

    double result = TinhGiaTri(pTotal, xValue);
    cout << "Gia tri P(" << xValue << ") = " << fixed << setprecision(2) << result << endl;

    return 0;
}