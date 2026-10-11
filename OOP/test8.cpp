// Bai tap 1.2.3

#include <bits/stdc++.h>

using namespace std;

class Diem{
private:
    float x, y;
public:
    void Nhap();
    void Xuat() const;
    float TinhKhoangCach(const Diem &p2) const;
};

class TamGiac{
private:
    Diem A, B, C;
public:
    void Nhap();
    void Xuat() const;
    float TinhChuVi() const;
    float TinhDienTich() const;
    string PhanLoai() const;
};

void Diem::Nhap(){
    cin >> x >> y;
}

void Diem::Xuat() const{
    cout << "(" << x << ", " << y << ")";
}

float Diem::TinhKhoangCach(const Diem &p2) const{
    return sqrt( pow(this->x - p2.x, 2) + pow(this->y - p2.y, 2) );
}

void TamGiac::Nhap(){
    do{
        cout << "Moi nhap cac diem: ";
        A.Nhap();
        B.Nhap();
        C.Nhap();
        cout << "\n";
    }
    while (!(A.TinhKhoangCach(B) + B.TinhKhoangCach(C) > C.TinhKhoangCach(A) && A.TinhKhoangCach(B) + A.TinhKhoangCach(C) > B.TinhKhoangCach(C) && B.TinhKhoangCach(C) + A.TinhKhoangCach(C) > A.TinhKhoangCach(B)));
}

void TamGiac::Xuat() const{
    cout << "A" << A.Xuat() << ", B" << B.Xuat() << ", C" << C.Xuat() << "\n";
}

float TamGiac::TinhChuVi() const{
    return A.TinhKhoangCach(B) + B.TinhKhoangCach(C) + A.TinhKhoangCach(C);
}

float TamGiac::TinhDienTich() const{
    float ab = A.TinhKhoangCach(B), bc = B.TinhKhoangCach(C), ac = A.TinhKhoangCach(C);
    float P = TinhChuVi() / 2.0;
    return sqrt(P * (P - ab) * (P - ac) * (P - bc));
}

string TamGiac::PhanLoai() const{
    float ab = A.TinhKhoangCach(B), bc = B.TinhKhoangCach(C), ac = A.TinhKhoangCach(C);
    if (ab == bc && bc == ac){
        return "Tam giac deu";
    }
    else if (ab == bc || ab == ac || bc == ac){
        return "Tam giac can";
    }
    else if (pow(ab, 2) == pow(bc, 2) + pow(ac, 2) || pow(bc, 2) == pow(ab, 2) + pow(ac, 2) || pow(ac, 2) == pow(ab, 2) + pow(bc, 2)){
        return "Tam giac vuong";
    }
    return "Tam giac thuong";
}

int main(){


    return 0;
}