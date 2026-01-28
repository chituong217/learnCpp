#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

struct ThoiGian{
    int gio, phut, giay;
};

ThoiGian* TaoThoiGian(int h, int m, int s){
    ThoiGian *t = new ThoiGian;
    *t = {h, m, s};
    return t;
}

void HopLeThoiGian(ThoiGian* pTG){
    if (pTG->giay >= 60){
        pTG->phut += pTG->giay / 60;
        pTG->giay %= 60;
    }
    if (pTG->phut >= 60){
        pTG->gio += pTG->phut / 60;
        pTG->phut %= 60;
    }
}

void XuatTG(ostream &os, const ThoiGian* pTG){
    if (pTG->gio < 10) os << "0";
    os << pTG->gio << ":";
    
    if (pTG->phut < 10) os << "0";
    os << pTG->phut << ":";
    
    if (pTG->giay < 10) os << "0";
    os << pTG->giay;
}

ThoiGian* KhoangCachThoiGian(ThoiGian* pTG1, ThoiGian* pTG2){
    ThoiGian *t = new ThoiGian;
    long long s1 = pTG1->gio * 3600 + pTG1->phut * 60 + pTG1->giay;
    long long s2 = pTG2->gio * 3600 + pTG2->phut * 60 + pTG2->giay;
    long long s = abs(s2 - s1);
    int gio = s / 3600;
    s %= 3600;
    int phut = s / 60;
    s %= 60;
    t->gio = gio;
    t->phut = phut;
    t->giay = s;
    return t;
}

int main(){
    srand(3072);
    ThoiGian *pTG1, *pTG2;
    pTG1 = TaoThoiGian(rand() % 100, rand() % 100, rand() % 100);
    pTG2 = TaoThoiGian(rand() % 100, rand() % 100, rand() % 100);

    cout << "Thoi gian 1: ";
    XuatTG(cout, pTG1);
    cout << endl << "Thoi gian 2: ";
    XuatTG(cout, pTG2);
    cout << endl << endl;

    HopLeThoiGian(pTG1);
    HopLeThoiGian(pTG2);

    cout << "Thoi gian sau khi hop le";
    cout << endl << "Thoi gian 1: ";
    XuatTG(cout, pTG1);
    cout << endl << "Thoi gian 2: ";
    XuatTG(cout, pTG2);
    cout << endl << endl;

    ThoiGian* p = KhoangCachThoiGian(pTG1, pTG2);
    cout << "Khoang cach 2 thoi gian tren: ";
    XuatTG(cout, p);
    cout << endl;

    delete pTG1;
    delete pTG2;
    delete p;
    system("pause");
    return 0;
}