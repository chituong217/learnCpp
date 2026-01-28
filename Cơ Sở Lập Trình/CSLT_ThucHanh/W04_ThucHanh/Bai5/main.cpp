#include "Function.h"
#include <fstream>

int main(){
    STamGiac tg;
    cout << "Hay nhap vao 3 canh cua tam giac: ";
    nhap(cin, tg);
    cout << "Cac canh cua tam giac lan luot la :";
    xuat(cout, tg);
    cout << endl;

    double c = chuvi(tg);
    cout << "Chu vi cua tam giac la: ";
    cout << c << endl;

    double s = dientich(tg);
    cout << "Dien tich cua tam giac la: ";
    cout << s << endl;
    return 0;
}