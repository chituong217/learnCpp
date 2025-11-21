#include <iostream>
#include "PhanSo.h"
using namespace std;

int main(){
    PhanSo ps1, ps2, tong;
    cout << "Hay nhap vao phan so thu 1:";
    nhapPhanSo(ps1);
    cout << "Hay nhap vao phan so thu 2:";
    nhapPhanSo(ps2);

    tong = congPhanSo(ps1, ps2);
    rutgonPhanSo(tong);

    cout << "Tong cua hai phan so ban vua nhap la :";
    xuatPhanSo(tong);

    return 0;
}