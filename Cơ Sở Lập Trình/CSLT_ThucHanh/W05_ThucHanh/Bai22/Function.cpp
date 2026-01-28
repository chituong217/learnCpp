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
    is.ignore();
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

void sort(PhanSo a[], int n){
    for (int i=0; i<n; i++){
        int min_pos = i;
        for (int j = i+1; j < n; j++){
            if (sosanhPhanSo(a[min_pos], a[j]) <= 0){
                min_pos = j;
            }
        }
        PhanSo tmp = a[min_pos];
        a[min_pos] = a[i];
        a[i] = tmp;
    }
}