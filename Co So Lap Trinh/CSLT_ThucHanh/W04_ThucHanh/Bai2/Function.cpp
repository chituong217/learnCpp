#include "Function.h"

int ucln(int a, int b){
    while (b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void nhapPhanSo(istream &is, PhanSo &ps){
    is >> ps.tu;
    if (is.fail()){
        is.clear();
        ps.tu = 1;
    }
    is >> ps.mau;
    if (is.fail()){
        is.clear();
        ps.mau = 1;
    }
}

void xuatPhanSo(PhanSo ps){
    if (ps.tu == 0 || ps.mau == 1){
        cout << ps.tu << endl;
    }
    else{
        if (ps.mau < 0){
            cout << -1*ps.tu << "/" << -1*ps.mau << endl;
        }
        else{
            cout << ps.tu << "/" << ps.mau << endl;
        }
    }
}

PhanSo congPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo tong;
    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    return tong;
}

PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo hieu;
    hieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    hieu.mau = ps1.mau * ps2.mau;
    return hieu;
}

PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo tich;
    tich.tu = ps1.tu * ps2.tu;
    tich.mau = ps1.mau * ps2.mau;
    return tich;
}

PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo thuong;
    thuong.tu = ps1.tu * ps2.mau;
    thuong.mau = ps1.mau * ps2.tu;
    return thuong;
}

void rutgonPhanSo(PhanSo &ps){
    int uocchung = ucln(ps.tu, ps.mau);
    ps.tu /= uocchung;
    ps.mau /= uocchung;
}

int checkToiGian(PhanSo ps){
    if (abs(ucln(ps.tu, ps.mau)) != 1){
        return 0;
    }
    return 1;
}

int checkAmDuong(PhanSo ps){
    if ( (long long)ps.tu * ps.mau > 0 ){
    return 1;
    }
    else if ( (long long)ps.tu * ps.mau < 0 ){
     return -1;
    }
    else {
     return 1;
    }
}
int sosanhPhanSo(PhanSo ps1, PhanSo ps2){
    if (ps1.mau < 0) {
    ps1.tu *= -1;
     ps1.mau *= -1;
    }
    if (ps2.mau < 0) {
        ps2.tu *= -1;
        ps2.mau *= -1;
    }
    int tu1 = ps1.tu * ps2.mau;
    int tu2 = ps2.tu * ps1.mau;
    if (tu1 > tu2){
        return 1;
    }
    else if (tu1 == tu2){
        return 0;
    }
    else{
        return -1;
    }
}
