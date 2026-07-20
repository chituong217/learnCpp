#include "Function.h"

void nhap(istream &in, STamGiac &tg){
    in >> tg.a;
    in >> tg.b;
    in >> tg.c;
}

void xuat(ostream &out, STamGiac tg){
    out << tg.a << " " << tg.b << " " << tg.c;
}

double chuvi(STamGiac tg){
    double chuvi = tg.a + tg.b + tg.c;
    return chuvi;
}

double dientich(STamGiac tg){
    double p = chuvi(tg)/2;
    double dientich = sqrt ( p * (p-tg.a) * (p-tg.b) * (p-tg.c) );
    return dientich;
}