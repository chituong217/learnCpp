#include <iostream>
#include "PhanSo.h"
using namespace std;

int ucln(int a, int b){
    while (b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void nhapPhanSo(PhanSo &ps){
    cout << "Nhap vao tu so:";
    cin >> ps.tu;
    do {
        cout << "Nhap vao mau so (Khac 0):";
        cin >> ps.mau;
    }
    while (ps.mau == 0);
}

void xuatPhanSo(PhanSo ps){
    if (ps.tu == 0 || ps.mau == 1){
        cout << ps.tu << endl;
    }
    else{
        cout << ps.tu << "/" << ps.mau << endl;
    }
}

PhanSo congPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo tong;
    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    return tong;
}

void rutgonPhanSo(PhanSo &ps){
    int uocchung = ucln(ps.tu, ps.mau);
    ps.tu /= uocchung;
    ps.mau /= uocchung;
}
