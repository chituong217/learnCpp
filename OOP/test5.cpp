#include <bits/stdc++.h>

using namespace std;

class HocSinh{
private:
    string hoten;
    float toan, van, dtb;
public:
    void Nhap();
    void TinhDTB();
    string XepLoai();
    void Xuat();
};

void HocSinh::Nhap(){
    getline(cin, hoten);
    cin >> toan;
    while (toan < 0 || toan > 10){
        cout << "Moi nhap lai diem toan: ";
        cin >> toan;
        cout << "\n";
    }
    cin >> van;
    while (van < 0 || van > 10){
        cout << "Moi nhap lai diem van: ";
        cin >> van;
        cout << "\n";
    }

    this->TinhDTB();
}

void HocSinh::TinhDTB(){
    dtb = (toan + van) / 2.0;
}

string HocSinh::XepLoai(){
    if (dtb >= 9.0){
        return "Xuat sac";
    }
    else if (dtb >= 8.0){
        return "Kha";
    }
    else if (dtb >= 5.0){
        return "Trung binh";
    }
    else{
        return "Yeu";
    }
}

void HocSinh::Xuat(){
    cout << hoten << " " << setprecision(2) << fixed << toan << " " << van << " " << dtb << " " << this->XepLoai() << "\n";
}

int main(){

    return 0;
}