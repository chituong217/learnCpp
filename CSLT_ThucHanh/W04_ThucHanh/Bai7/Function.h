#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <fstream>

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


#endif