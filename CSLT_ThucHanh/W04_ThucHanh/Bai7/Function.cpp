#include "Function.h"

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
