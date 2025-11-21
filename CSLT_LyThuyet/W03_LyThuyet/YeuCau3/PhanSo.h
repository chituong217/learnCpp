#ifndef _FUNC_
#define _FUNC_

struct PhanSo{
    int tu;
    int mau;
};

int ucln(int a, int b);
void nhapPhanSo(PhanSo &ps);
void xuatPhanSo(PhanSo ps);
PhanSo congPhanSo(PhanSo ps1, PhanSo ps2);
void rutgonPhanSo(PhanSo &ps);

#endif