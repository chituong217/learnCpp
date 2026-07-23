#include <bits/stdc++.h>

using namespace std;

class ThiSinh{
private:
    string hoten, ngaysinh;
    double diem1, diem2, diem3;
    static string tenTruong;
public:
    void nhap();
    double tinhTongDiem();
    void xuat();
    string getTenTruong();
    void setTenTruong(string tenTruongMoi);
};

string ThiSinh::tenTruong = "HCMUS";

void ThiSinh::nhap(){
    getline(cin, this->hoten);
    getline(cin, this->ngaysinh);
    cin >> this->diem1 >> this->diem2 >> this->diem3;
}

double ThiSinh::tinhTongDiem(){
    return (this->diem1 + this->diem2 + this->diem3);
}

void ThiSinh::xuat(){
    cout << this->hoten << " " << this->ngaysinh << " " << fixed << setprecision(1) << tinhTongDiem() << endl;
}

string ThiSinh::getTenTruong(){
    return this->tenTruong;
}

void ThiSinh::setTenTruong(string tenTruongMoi){
    this->tenTruong = tenTruongMoi;
}

int main(){
    ThiSinh x;
    cout << x.getTenTruong() << endl;

    ThiSinh y;
    y.setTenTruong("ULAW");

    cout << x.getTenTruong()<< " " << y.getTenTruong() << endl;

    return 0;
}