#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct STamGiac{
    double a;
    double b;
    double c;
};

void nhap(istream &in, STamGiac &tg);

void xuat(ostream &out, STamGiac tg);

double chuvi(STamGiac tg);

double dientich(STamGiac tg);

#endif