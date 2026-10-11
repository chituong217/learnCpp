// Bai tap 1.1

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class PhanSo{
private:
    int tu, mau;
public:
    void Nhap();
    void Xuat();
    void RutGon();
    int KiemTraDau();
};

void PhanSo::Nhap(){
    cout << "Moi nhap phan so: ";
    cin >> tu >> mau;
    cout << "\n";
    while (mau == 0){
        cout << "Loi, moi nhap lai phan so: ";
        cin >> tu >> mau;
        cout << "\n";
    }

    this->RutGon();
}

void PhanSo::Xuat(){
    cout << tu << "/" << mau;
}

void PhanSo::RutGon(){
    if (tu == 0){
        mau = 1;
        return;
    }
    if (mau < 0){
        tu *= -1;
        mau *= -1;
    }

    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
}

int PhanSo::KiemTraDau(){
    if (tu == 0) return 0;
    else if (tu > 0) return 1;
    else return -1;
}

int main(){


    return 0;
}