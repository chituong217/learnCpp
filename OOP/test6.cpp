// Bai tap 1.2.1

#include <bits/stdc++.h>

using namespace std;

class TaiKhoanNganHang{
private:
    string soTaiKhoan;
    string tenChuTaiKhoan;
    double soDu;
public:
    TaiKhoanNganHang(){

    }

    TaiKhoanNganHang(string stk, string ten, double soDuBanDau);
    bool NapTien(double soTien);
    bool RutTien(double soTien);
    void InSaoKe() const;
    double GetSoDu() const;
};

TaiKhoanNganHang::TaiKhoanNganHang(string stk, string ten, double soDuBanDau){
    this->soTaiKhoan = stk;
    this->tenChuTaiKhoan = ten;
    this->soDu = soDuBanDau;
}

bool TaiKhoanNganHang::NapTien(double soTien){
    if (soTien > 0){
        this->soDu += soTien;
        return true;
    }
    return false;
}

bool TaiKhoanNganHang::RutTien(double soTien){
    if (soTien > 0 && soTien <= soDu){
        soDu -= soTien;
        return true;
    }
    return false;
}

void TaiKhoanNganHang::InSaoKe() const{
    cout << soTaiKhoan << " " << tenChuTaiKhoan << " " << soDu << " VND\n";
}

double TaiKhoanNganHang::GetSoDu() const{
    return soDu;
}

int main(){

    return 0;
}