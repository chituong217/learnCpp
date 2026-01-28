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

void nhapDate(istream &in, SNgay &date);
void xuatDate(ostream &out, SNgay date);
bool checkNamnhuan(SNgay date);
int tinhSTTngaytrongnam(SNgay date);

void nhap(istream &in, SSinhVien &sv);
void xuat(ostream &out, SSinhVien sv);
int tinhTuoi(SSinhVien sv);
int sosanhTen(SSinhVien sv1, SSinhVien sv2);
int sosanhTuoi(SSinhVien sv1, SSinhVien sv2);

void swapSV(SSinhVien &sv1, SSinhVien &sv2);
void sapXep(SSinhVien a[], int n);


int main(){
    int n;
    cin >> n;
    SSinhVien a[MAX_LEN];
    for (int i=0; i<n; i++){
        nhap(cin, a[i]);
    }
    cout << "\n--- DANH SACH TRUOC KHI SAP XEP ---" << endl;
    for (int i = 0; i < n; i++) {
        xuat(cout, a[i]);
    }
    sapXep(a, n);
    cout << "\n--- DANH SACH SAU KHI SAP XEP (QueQuan -> Tuoi -> Ten) ---" << endl;
    for (int i = 0; i < n; i++) {
        xuat(cout, a[i]);
    }
    return 0;
}


void nhapDate(istream &in, SNgay &date){
    in >> date.d;
    in >> date.m;
    in >> date.y;
}

void xuatDate(ostream &out, SNgay date){
    out << "Date : day " << date.d << " month " << date.m << " year " << date.y << endl;
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



void nhap(istream &in, SSinhVien &sv){
    in >> sv.id;
    in.ignore();
    in.getline(sv.name, 51);
    in >> sv.gpa;
    in.ignore();
    in.getline(sv.quequan, 101);
    nhapDate(in, sv.date);
}

void xuat(ostream &out, SSinhVien sv){
    out << sv.id << "-" << sv.name << "-" << sv.gpa << "-" << sv.quequan << "-";
    xuatDate(cout, sv.date);
}

int tinhTuoi(SSinhVien sv){
    // Xet den 2/11/2025
    SNgay today = {2, 11, 2025};
    int age = 2025 - sv.date.y - 1;
    SNgay des = {sv.date.d, sv.date.m, 2025};
    int check = tinhSTTngaytrongnam(des) - tinhSTTngaytrongnam(today);
    if (check <= 0){
        age++;
    }
    return age;
}

int sosanhTen(SSinhVien sv1, SSinhVien sv2){
    if (strcmp(sv1.name, sv2.name) < 0){
        return -1;
    }
    else if (strcmp(sv1.name, sv2.name) > 0){
        return 1;
    }
    else{
        return 0;
    }
}

int sosanhTuoi(SSinhVien sv1, SSinhVien sv2){
    int ss = tinhTuoi(sv1) - tinhTuoi(sv2);
    if (ss > 0){
        return 1;
    }
    else if (ss == 0){
        return 0;
    }
    else{
        return -1;
    }
}



void swapSV(SSinhVien &sv1, SSinhVien &sv2) {
    SSinhVien temp = sv1;
    sv1 = sv2;
    sv2 = temp;
}

void sapXep(SSinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool canSwap = false;
            int queQuanCmp = strcmp(a[j].quequan, a[j + 1].quequan);
            if (queQuanCmp > 0) {
                canSwap = true;
            } 
            else if (queQuanCmp == 0) {
                int tuoiCmp = sosanhTuoi(a[j], a[j + 1]);
                if (tuoiCmp > 0) {
                    canSwap = true;
                } 
                else if (tuoiCmp == 0) {
                    int tenCmp = sosanhTen(a[j], a[j + 1]);
                    if (tenCmp > 0) {
                        canSwap = true;
                    }
                }
            }
            if (canSwap) {
                swapSV(a[j], a[j + 1]);
            }
        }
    }
}