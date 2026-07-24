#include <bits/stdc++.h>

using namespace std;

class NV{
private:
    string manv, hoten;
    long long luongcoban;
    int songaycong;
    string chucvu;

    long long luong, thuong, phucap, thunhap;
public:
    friend istream& operator >> (istream &in, NV &x){
        getline(in, x.hoten);
        in >> x.luongcoban >> x.songaycong >> x.chucvu;

        return in;
    }

    friend ostream& operator << (ostream &out, NV x){
        out << x.manv << " " << x.hoten << " " << x.luong << " " << x.thuong << " " << x.phucap << " " << x.thunhap << endl;

        return out;
    }

    void setMaNV();
    void tinhThuNhap();
};

void NV::setMaNV(){
    this->manv = "NV01";
}

void NV::tinhThuNhap(){
    luong = luongcoban * songaycong;
    if (songaycong >= 25) thuong = 0.2 * luong;
    else if (songaycong >= 22) thuong = 0.1 * luong;
    else thuong = 0;

    if (chucvu == "GD") phucap = 250000;
    else if (chucvu == "PGD") phucap = 200000;
    else if (chucvu == "TP") phucap = 180000;
    else if (chucvu == "NV") phucap = 150000;

    thunhap = luong + thuong + phucap;
}

int main(){
    NV x;
    cin >> x;
    x.setMaNV();
    x.tinhThuNhap();
    cout << x;

    return 0;
}