#include <bits/stdc++.h>

using namespace std;

class HocSinh{
private:
    string hoten;
    float toan, van, dtb;
public:
    void Nhap();
    void TinhDTB();
    string XepLoai() const;
    void Xuat() const;
    float getDTB() const;
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
    cin.ignore();

    this->TinhDTB();
}

void HocSinh::TinhDTB(){
    dtb = (toan + van) / 2.0;
}

string HocSinh::XepLoai() const{
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

void HocSinh::Xuat() const{
    cout << hoten << " " << setprecision(2) << fixed << toan << " " << van << " " << dtb << " " << this->XepLoai() << "\n";
}

float HocSinh::getDTB() const{
    return this->dtb;
}

class DSHS{
private:
    HocSinh ds[101];
    int n;
public:
    void Nhap();
    void Xuat() const;
    void SapXepGiamTheoDTB();
    void TimHocSinhXuatSac() const;
    float TinhDTBChungCaLop() const;
};

void DSHS::Nhap(){
    do{
        cin >> n;
    }
    while (n < 0 || n > 100);
    cin.ignore();

    for (int i = 0; i < n; i++){
        ds[i].Nhap();
    }
}

void DSHS::Xuat() const{
    for (int i = 0; i < n; i++){
        ds[i].Xuat();
    }
}

void DSHS::SapXepGiamTheoDTB(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (ds[j].getDTB() < ds[j + 1].getDTB()){
                swap(ds[j], ds[j + 1]);
            }
        }
    }
}

void DSHS::TimHocSinhXuatSac() const{
    for (int i = 0; i < n; i++){
        if (ds[i].XepLoai() == "Xuat sac"){
            ds[i].Xuat();
        }
    }
}

float DSHS::TinhDTBChungCaLop() const{
    float gpa = 0;
    for (int i = 0; i < n; i++){
        gpa += ds[i].getDTB();
    }
    return gpa / (1.0 * n);
}

int main(){

    return 0;
}