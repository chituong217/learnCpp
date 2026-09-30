#include <bits/stdc++.h>

using namespace std;

class Phong{
protected:
    string maPhong, tenKhach;
    int soNgayThue;
    long long donGia;

    long long tongTien;
public:
    void setMaPhong(string maPhong){
        this->maPhong = maPhong;
    }

    virtual void nhap(istream &in){
        getline(in, tenKhach);
        in >> soNgayThue >> donGia;
    }

    virtual void xuat(ostream &out){
        out << maPhong << " - " << tenKhach << " - " << maPhong.substr(0, 3) << " ";
    }
    virtual long long tinhTien() = 0;
    virtual ~Phong(){}

    string getTenKhach(){
        return tenKhach;
    }
    string getMaPhong(){
        return maPhong;
    }
    long long getTongTien(){
        return tongTien;
    }

    friend bool comp(Phong *a, Phong *b);
};

bool comp(Phong *a, Phong *b){
    if (a->tongTien != b->tongTien){
        return a->tongTien > b->tongTien;
    }
    return a->tenKhach < b->tenKhach;
}

class PhongStandard : public Phong{
private:
    long long phiDichVu;
public:
    void nhap(istream &in) override{
        Phong::nhap(in);
        in >> phiDichVu;
        in.ignore();
        tongTien = tinhTien();
    }

    void xuat(ostream &out) override{
        Phong::xuat(out);
        if (soNgayThue > 5){
            out << "(Giam 10%) ";
        }
        out << "-> Thanh tien: " << tongTien << " VND\n";
    }
    long long tinhTien() override{
        long long tongTien = (soNgayThue * donGia) + phiDichVu;
        if (soNgayThue > 5){
            tongTien *= 0.9;
        }

        return tongTien;
    }
};

class PhongVIP : public Phong{
private:
    string loaiGoiVIP;
public:
    void nhap(istream &in) override{
        Phong::nhap(in);
        in.ignore();
        getline(in, loaiGoiVIP);
        tongTien = tinhTien();
    }

    void xuat(ostream &out) override{
        Phong::xuat(out);
        out << "(" << loaiGoiVIP << ") -> Thanh tien: " << tongTien << " VND\n";
    }
    long long tinhTien() override{
        long long tongTien = soNgayThue * donGia;
        long long phuThu = 0;
        if (loaiGoiVIP == "Diamond"){
            phuThu = 2000000;
        }
        else if (loaiGoiVIP == "Gold"){
            phuThu = 1000000;
        }

        return tongTien + phuThu;
    }
};

int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector<Phong*> v(n);
    for (int i = 0; i < n; i++){
        string maPhong;
        getline(cin, maPhong);
        if (maPhong.substr(0, 3) == "STD"){
            v[i] = new PhongStandard;
        }
        else{
            v[i] = new PhongVIP;
        }
        v[i]->setMaPhong(maPhong);
        v[i]->nhap(cin);
    }

    long long tongDoanhThu = 0;
    for (auto x : v){
        tongDoanhThu += x->getTongTien();
    }
    cout << "=== TONG DOANH THU KHACH SAN: " << tongDoanhThu << " VND ===\n";

    sort(v.begin(), v.end(), comp);
    cout << "=== DANH SACH HOA DON SAU KHI SAP XEP ===\n";
    for (auto x : v){
        x->xuat(cout);
    }

    for (auto x : v){
        delete x;
    }

    return 0;
}