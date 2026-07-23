#include <bits/stdc++.h>

using namespace std;

class ThiSinh{
private:
    string hoten, ngaysinh;
    double diem1, diem2, diem3, tongdiem;

public:
    void nhap();
    void tinhTongDiem();
    void xuat();
};

void ThiSinh::nhap(){
    getline(cin, this->hoten);
    getline(cin, this->ngaysinh);
    cin >> this->diem1 >> this->diem2 >> this->diem3;
}

void ThiSinh::tinhTongDiem(){
    this->tongdiem = (this->diem1 + this->diem2 + this->diem3);
}

void ThiSinh::xuat(){
    cout << this->hoten << " " << this->ngaysinh << " " << fixed << setprecision(1) << this->tongdiem << endl;
}

int main(){
    ThiSinh x;
    x.nhap();
    x.tinhTongDiem();
    x.xuat();

    return 0;
}