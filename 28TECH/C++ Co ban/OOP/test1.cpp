#include <bits/stdc++.h>

using namespace std;

class SinhVien{
private:
    // data field
    string ten, ngaysinh, lop;
    double gpa;
public:
    // constructor
    SinhVien(){
        cout << "Constructor mac dinh\n";
    }
    SinhVien(string ten, string ngaysinh, string lop, double gpa){
        cout << "Constructor day du tham so\n";
        this->ten = ten;
        this->ngaysinh = ngaysinh;
        this->lop = lop;
        this->gpa = gpa;
    }

    // method
    void nhapThongTin();
    void xuatThongTin();
    void xinchao();
    string getTen();
    void setTen(string tenMoi);

    // destructor
    ~SinhVien(){
        cout << "Doi tuong bi huy\n";
    }
};

void SinhVien::nhapThongTin(){
    getline(cin, this->ten);
    cin >> this->ngaysinh >> this->lop >> this->gpa;
}

void SinhVien::xuatThongTin(){
    cout << this->ten << ' ' << this->ngaysinh << ' ' << this->lop << ' ' << this->gpa << endl;
}

void SinhVien::xinchao(){
    cout << "Sinh vien " << this->ten << " xin chao\n";
}

string SinhVien::getTen(){
    return this->ten;
}

void SinhVien::setTen(string tenMoi){
    this->ten = tenMoi;
}

int main(){
    SinhVien x;
    SinhVien y("Bo", "24/12/2007", "CTT6", 4.0);

    y.xuatThongTin();

    return 0;
}