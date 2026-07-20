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
PhanSo congPhanSo(PhanSo ps1, PhanSo ps2);
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2);
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2);
PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2);
void rutgonPhanSo(PhanSo &ps);
int checkToiGian(PhanSo ps);
int checkAmDuong(PhanSo ps);
int sosanhPhanSo(PhanSo ps1, PhanSo ps2);

#endif