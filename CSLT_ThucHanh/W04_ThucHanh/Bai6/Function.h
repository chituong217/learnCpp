#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct SNgay{
    int d;
    int m;
    int y;
};

void nhap(istream &in, SNgay &date);

void xuat(ostream &out, SNgay date);

bool checkNamnhuan(SNgay date);

int tinhSTTngaytrongnam(SNgay date);

long long tinhSTTngay(SNgay date);

SNgay timNgaytuSTT(long long stt);

SNgay tinhNgaytruocdokngay(SNgay date, int k);

SNgay tinhNgaysaudokngay(SNgay date, int k);

long long tinhKhoangcachhaingay(SNgay date1, SNgay date2);

int sosanhHaingay(SNgay date1, SNgay date2);

#endif