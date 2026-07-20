#include "Function.h"

void nhapDonThuc(ifstream &fIn, SDonThuc &dt){
    fIn >> dt.heso;
    fIn >> dt.somu;
}

void xuatDonThuc(ostream &Fout, SDonThuc dt){
    if (dt.heso == 0){
        Fout << "0";
        return;
    }
    if (dt.somu == 0){
        Fout << dt.heso;
        return;
    }

    if (dt.heso == -1){
        Fout << "-";
    }
    else if (dt.heso != 1){
        Fout << dt.heso;
    }

    Fout << "x";
    if (dt.somu != 1){
        Fout << "^" << dt.somu;
    }
}

SDonThuc tichDonThuc(SDonThuc dt1, SDonThuc dt2){
    SDonThuc tich;
    tich.heso = dt1.heso * dt2.heso;
    tich.somu = dt1.somu +dt2.somu;
    return tich;
}

SDonThuc thuongDonThuc(SDonThuc dt1, SDonThuc dt2){
    SDonThuc thuong;
    if (dt2.heso == 0){
        cout << "Loi, khong the chia don thuc." << endl;
        thuong.heso = 0;
        thuong.somu = 0;
        return thuong;
    }
    else {
        thuong.heso = dt1.heso / dt2.heso;
        thuong.somu = dt1.somu - dt2.somu;
        return thuong;
    }
}

SDonThuc DaoHamCap1(SDonThuc dt){
    SDonThuc daoham;
    if (dt.somu == 0){
        daoham.heso = 0;
        daoham.somu = 0;
    }
    else{
        daoham.heso = dt.heso * dt.somu;
        daoham.somu = dt.somu - 1;
    }
    
    return daoham;
}

SDonThuc DaoHamCapK(SDonThuc dt, int k){
    SDonThuc daoham = dt;
    for (int i = 1; i <= k; i++){
        daoham = DaoHamCap1(daoham);
        if (daoham.heso == 0){
            break;
        }
    }
    return daoham;
}

double tinhGiaTri(SDonThuc dt, double x0){
    double result = dt.heso * (pow(x0, dt.somu));
    return result;
}