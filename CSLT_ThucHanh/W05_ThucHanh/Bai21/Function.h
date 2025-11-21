#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

struct SDonThuc{
    double heso;
    int somu;
};


void nhapDonThuc(ifstream &Fin, SDonThuc &dt);

void xuatDonThuc(ostream &Fout, SDonThuc dt);

SDonThuc tichDonThuc(SDonThuc dt1, SDonThuc dt2);

SDonThuc thuongDonThuc(SDonThuc dt1, SDonThuc dt2);

SDonThuc DaoHamCap1(SDonThuc dt);

SDonThuc DaoHamCapK(SDonThuc dt, int k);

double tinhGiaTri(SDonThuc dt, double x0);

#endif