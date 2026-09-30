#include <bits/stdc++.h>

using namespace std;

class NhanVien{
protected:
    string maNV, hoTen;
    double heSoLuong;
    long long luong;
public:
    NhanVien(){

    }

    NhanVien(string maNV, string hoTen, double heSoLuong){
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->heSoLuong = heSoLuong;
    }

    virtual void nhap(istream &in){
        getline(in, maNV);
        getline(in, hoTen);
        in >> heSoLuong;
    }

    virtual void xuat(ostream &out){
        out << "[" << maNV.substr(0, 2) << "] " << maNV << " - " << hoTen << " - He so: " << heSoLuong << " - "; 
    }
    
    virtual long long tinhLuong() = 0;

    virtual ~NhanVien(){

    }

    string getMaNV(){
        return maNV;
    }
    string getHoTen(){
        return hoTen;
    }
    long long getLuong(){
        return luong;
    }
};

class CongNhan : public NhanVien{
private:
    int soNgayCong;
public:
    void nhap(istream &in) override{
        NhanVien::nhap(in);
        in >> soNgayCong;
        luong = tinhLuong();
    }

    void xuat(ostream &out) override{
        NhanVien::xuat(out);
        out << "Ngay cong: " << soNgayCong << " -> Luong: " << luong << " VND";
    }
    
    long long tinhLuong() override{
        return heSoLuong * 1500000 + soNgayCong * 100000;
    }
};

class KySu : public NhanVien{
private:
    int soGioOverTime;
public:
    void nhap(istream &in) override{
        NhanVien::nhap(in);
        in >> soGioOverTime;
        luong = tinhLuong();
    }

    void xuat(ostream &out) override{
        NhanVien::xuat(out);
        out << "Gio OT: " << soGioOverTime << " -> Luong: " << luong << " VND";
    }
    
    long long tinhLuong() override{
        return heSoLuong * 2000000 + soGioOverTime * 200000;
    }
};

int main(){
    int n;
    cin >> n;

    vector<NhanVien*> v(n);

    for (int i = 0; i < n; i++){
        cin.ignore();
        string ma;
        getline(cin, ma);

        if (ma == "CN"){
            v[i] = new CongNhan;
        }
        else{
            v[i] = new KySu;
        }

        v[i]->nhap(cin);
    }

    long long maxLuong = 0;
    NhanVien* nhanVienMaxLuong = NULL;
    cout << "=== BANG LUONG CONG TY ===\n";
    for (auto x : v){
        if (x->getLuong() > maxLuong){
            maxLuong = x->getLuong();
            nhanVienMaxLuong = x;
        }
        x->xuat(cout);
        cout << '\n';
    }

    cout << endl;
    cout << "=== NHAN VIEN LUONG CAO NHAT ===\n";
    cout << nhanVienMaxLuong->getMaNV() << " - " << nhanVienMaxLuong->getHoTen() << " -> Luong: " << nhanVienMaxLuong->getLuong() << "VND\n";

    for (auto x : v){
        delete x;
    }

    return 0;
}