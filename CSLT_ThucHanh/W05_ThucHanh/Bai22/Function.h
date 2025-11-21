#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct PhanSo{
    int tu;
    int mau;
};

int ucln(int a, int b);
void nhapPhanSo(istream &is, PhanSo &ps);
void xuatPhanSo(PhanSo ps);
void rutgonPhanSo(PhanSo &ps);
int checkToiGian(PhanSo ps);
int checkAmDuong(PhanSo ps);
int sosanhPhanSo(PhanSo ps1, PhanSo ps2);
void sort(PhanSo a[], int n);
#endif