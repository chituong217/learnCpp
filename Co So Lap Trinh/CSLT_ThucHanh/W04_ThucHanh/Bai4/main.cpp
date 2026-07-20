#include "Function.h"
#include <fstream>

int main(){
    SDiem d1, d2;

    cout << "Nhap toa do diem 1 (x;y): ";
    nhapDiem(cin, d1);

    cout << "Nhap toa do diem 2 (x;y): ";
    nhapDiem(cin, d2);

    cout << "Diem 1: ";
    xuatDiem(cout, d1);
    cout << endl;

    cout << "Diem 2: ";
    xuatDiem(cout, d2);
    cout << endl;

    double kc = tinhKhoangCach(d1, d2);
    cout << "Khoang cach giua d1 va d2: " << kc << endl;

    SDiem d_goc = timDoiXungGoc(d1);
    cout << "Doi xung qua goc toa do: ";
    xuatDiem(cout, d_goc);
    cout << endl;

    SDiem d_ox = timDoiXungOx(d1);
    cout << "Doi xung qua truc Ox: ";
    xuatDiem(cout, d_ox);
    cout << endl;

    SDiem d_oy = timDoiXungOy(d1);
    cout << "Doi xung qua truc Oy: ";
    xuatDiem(cout, d_oy);
    cout << endl;

    int phanTu = timPhanTu(d1);
    if (phanTu == 0) {
        cout << "Diem d1 nam tren truc toa do." << endl;
    } else {
        cout << "Diem d1 thuoc goc phan tu thu: " << phanTu << endl;
    }

    return 0;
}