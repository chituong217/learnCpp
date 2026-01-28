#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <fstream>
#define MAX_LEN 100

using namespace std;

struct SNgay{
    int d;
    int m;
    int y;
};

struct SSinhVien{
    int id;
    char name[51];
    float gpa;
    char quequan[101];
    SNgay date;
};

void nhapDate(istream &in, SNgay &date){
    in >> date.d;
    in >> date.m;
    in >> date.y;
}

void xuatDate(ostream &out, SNgay date){
    out << "Date : day " << date.d << " month " << date.m << " year " << date.y << endl;
}


void nhap(istream &in, SSinhVien &sv){
    cout << "Nhap ID: ";
    in >> sv.id;
    in.ignore();
    cout << "Nhap Ho Ten: ";
    in.getline(sv.name, 51);
    cout << "Nhap GPA: ";
    in >> sv.gpa;
    in.ignore();
    cout << "Nhap Que Quan: ";
    in.getline(sv.quequan, 101);
    cout << "Nhap Ngay Sinh (d m y): ";
    nhapDate(in, sv.date);
}

void xuat(ostream &out, SSinhVien sv){
    out << sv.id << "\t| " << sv.name << "\t| " << sv.gpa << "\t| " << sv.quequan << "\t| ";
    out << sv.date.d << "/" << sv.date.m << "/" << sv.date.y << endl;
}

bool checkNamnhuan(SNgay date){
    if ((date.y%400 == 0) || (date.y%4 == 0 && date.y%100 != 0)){
        return true;
    }
    else{
        return false;
    }
}

int tinhSTTngaytrongnam(SNgay date){
    int daysinMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (checkNamnhuan(date)){
        daysinMonth[2] = 29;
    }
    int stt = date.d;
    for (int i = 1; i < date.m; i++){
        stt += daysinMonth[i];
    }
    return stt;
}

int tinhTuoi(SSinhVien sv){
    SNgay today = {9, 11, 2025};
    int age = 2025 - sv.date.y;
    if (sv.date.m > today.m || (sv.date.m == today.m && sv.date.d > today.d)) {
        age--;
    }
    return age;
}



struct SLopHoc{
    char TenLop[101];
    SSinhVien DSSinhVien[MAX_LEN]; 
    unsigned int SiSo;            
};


void themSinhVien(SLopHoc &lop, SSinhVien sv) {
    lop.DSSinhVien[lop.SiSo] = sv;
    lop.SiSo++;
}

void xuatThongTinLop(ostream &out, SLopHoc lop) {
    out << "---------------------------------------------" << endl;
    out << "THONG TIN LOP HOC" << endl;
    out << "Ten Lop: " << lop.TenLop << endl;
    out << "Si So: " << lop.SiSo << endl;
    out << "--- Danh Sach Sinh Vien ---" << endl;
    out << "ID\t| Ho Ten\t| GPA\t| Que Quan\t| Ngay Sinh" << endl;
    
    for (unsigned int i = 0; i < lop.SiSo; i++) {
        xuat(out, lop.DSSinhVien[i]);
    }
    out << "---------------------------------------------" << endl;
}


void timSinhVienTheoTen(SLopHoc lop, char tenCanTim[]) {
    cout << "\n--- Ket qua tim kiem ten \"" << tenCanTim << "\" ---" << endl;
    bool timThay = false;
    for (unsigned int i = 0; i < lop.SiSo; i++) {
        if (strstr(lop.DSSinhVien[i].name, tenCanTim) != NULL) {
            xuat(cout, lop.DSSinhVien[i]);
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien nao co ten chua \"" << tenCanTim << "\"" << endl;
    }
}


void timSinhVienTheoTuoi(SLopHoc lop, int tuoiCanTim) {
    cout << "\n--- Ket qua tim kiem tuoi " << tuoiCanTim << " ---" << endl;
    bool timThay = false;
    for (unsigned int i = 0; i < lop.SiSo; i++) {
        if (tinhTuoi(lop.DSSinhVien[i]) == tuoiCanTim) {
            xuat(cout, lop.DSSinhVien[i]);
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien nao " << tuoiCanTim << " tuoi." << endl;
    }
}

int main(){
    SLopHoc lop;
    cout << "Nhap ten lop hoc: ";
    cin.getline(lop.TenLop, 101);
    lop.SiSo = 0; 
    int n;
    cout << "Ban muon them bao nhieu sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---" << endl;
        SSinhVien svMoi;
        nhap(cin, svMoi); 
        themSinhVien(lop, svMoi);
        cin.ignore(); 
    }

    xuatThongTinLop(cout, lop);

    char tenTim[51];
    cout << "\nNhap ten sinh vien can tim: ";
    cin.getline(tenTim, 51);
    timSinhVienTheoTen(lop, tenTim);

    int tuoiTim;
    cout << "\nNhap tuoi sinh vien can tim: ";
    cin >> tuoiTim;
    timSinhVienTheoTuoi(lop, tuoiTim);
    
    return 0;
}