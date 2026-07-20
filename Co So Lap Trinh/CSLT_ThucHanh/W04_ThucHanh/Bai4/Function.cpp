#include "Function.h"

void nhapDiem(istream &in, SDiem &d){
    in >> d.x;
    in >> d.y;
}

void xuatDiem(ostream &out, SDiem d){
    out << "(" << d.x << ";" << d.y << ")";
}

double tinhKhoangCach(SDiem d1, SDiem d2){
    double dx = d1.x - d2.x;
    double dy = d1.y - d2.y;
    return sqrt(dx * dx + dy * dy);
}

SDiem timDoiXungGoc(SDiem d){
    SDiem doixung;
    doixung.x = d.x * -1;
    doixung.y = d.y * -1;
    return doixung;
}

SDiem timDoiXungOx(SDiem d){
    SDiem doixung;
    doixung.x = d.x;
    doixung.y = d.y * -1;
    return doixung;
}

SDiem timDoiXungOy(SDiem d){
    SDiem doixung;
    doixung.x = d.x * -1;
    doixung.y = d.y;
    return doixung;
}

int timPhanTu(SDiem d){
    if ( d.x == 0 || d.y == 0 ){
        return 0;
    }
    else if (d.x >0 && d.y > 0){
        return 1;
    }
    else if (d.x < 0 && d.y > 0){
        return 2;
    }
    else if (d.x < 0 && d.y < 0){
        return 3;
    }
    else{
        return 4;
    }
}