#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct SDiem{
    double x;
    double y;
};

void nhapDiem(istream &fIn, SDiem &d);

void xuatDiem(ostream &Fout, SDiem d);

double tinhKhoangCach(SDiem d1, SDiem d2);

SDiem timDoiXungGoc(SDiem d);

SDiem timDoiXungOx(SDiem d);

SDiem timDoiXungOy(SDiem d);

int timPhanTu(SDiem d);


#endif