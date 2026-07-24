#include <bits/stdc++.h>

using namespace std;

class GV{
private:
    string mangach, hoten;
    int bacluong;
    long long luongcoban;
    long long luong;
public:
    friend istream& operator >> (istream &in, GV &x){
        getline(in, x.mangach);
        getline(in, x.hoten);
        in >> x.luongcoban;

        return in;
    }

    friend ostream& operator << (ostream &out, GV x){
        out << x.mangach << ' ' << x.hoten << ' ' << x.bacluong << ' ' << x.luong << endl;
        
        return out;
    }

    void tinhLuongVaBacLuong();
};

void GV::tinhLuongVaBacLuong(){
    string chucvu = mangach.substr(0, 2);
    string bacluongS = mangach.substr(2, 2);

    this->bacluong = stoi(bacluongS);
    this->luong = 1ll * luongcoban * this->bacluong;
    if (chucvu == "HT") luong += 2000000;
    else if (chucvu == "HP") luong += 900000;
    else if (chucvu == "GV") luong += 500000;
}

int main(){
    GV x;
    cin >> x;
    x.tinhLuongVaBacLuong();
    cout << x;

    return 0;
}