#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.14159

struct Diem {
    float x, y;
};

struct DuongTron {
    Diem* tam;
    float banKinh;
};

DuongTron* TaoDuongTron(float xV, float yV, float rV);
void XoaDuongTron(DuongTron* p);
void PrintDuongTron(ostream &os, DuongTron* p);
DuongTron* ChuViLonNhat(DuongTron** l, int n);
float TongDienTich(DuongTron** l, int n);
int XuatCacDuongTronDTLonHonTB(DuongTron** l, int n);
void XuatDuongTronChuViGiam(DuongTron** l, int n);
void XoaDsDuongTron(DuongTron** l, int n);

void main2(){
    srand(4003);

    int n = 5 + rand() % 20;

    DuongTron* *listDT = new DuongTron*[n];
    if (listDT == NULL)
    {
        return;
    }

    float xV, yV, rV;
    for (int i = 0; i < n; ++i)
    {
        xV = (rand() % 1000) * 1.0f / 50;
        yV = (rand() % 1000) * 1.0f / 50;
        rV = (rand() % 1000 + 1) * 1.0f / 50;
        listDT[i] = TaoDuongTron(xV, yV, rV);
    }

    cout << "Duong tron co chu vi lon nhat: ";
    DuongTron* pDTPMax = ChuViLonNhat(listDT, n);
    PrintDuongTron(cout, pDTPMax);
    cout << endl << endl;


    cout << "Tong dien tich: " << TongDienTich(listDT, n);
    cout << endl << endl;


    cout << "Cac duong tron co dien tich lon hon TB:";
    int dem = XuatCacDuongTronDTLonHonTB(listDT, n);
    
    cout << "So luong: " << dem;
    cout << endl << endl;

    cout << "Ds duong tron chu vi giam dan: ";
    XuatDuongTronChuViGiam(listDT, n);
    cout << endl << endl;

    XoaDsDuongTron(listDT, n);

    system("pause");
}

int main() {
    main2();
    return 0;
}


DuongTron* TaoDuongTron(float xV, float yV, float rV) {
    DuongTron *t = new DuongTron;
    Diem *o = new Diem;
    o->x = xV;
    o->y = yV;
    t->tam = o;
    t->banKinh = rV;
    return t;
}

void XoaDuongTron(DuongTron* p) {
    delete p->tam;
    delete p;
}

void PrintDuongTron(ostream &os, DuongTron* p) {
    os << fixed << setprecision(2) << "[" << "(" << p->tam->x << "," << p->tam->y << ")" << ", " << p->banKinh << "]";
}

DuongTron* ChuViLonNhat(DuongTron** l, int n) {
    DuongTron *MaxS = l[0];
    float max = l[0]->banKinh;
    for (int i = 1; i < n; i++){
        if (l[i]->banKinh > max){
            max = l[i]->banKinh;
            MaxS = l[i];
        }
    }
    return MaxS;
}

float TongDienTich(DuongTron** l, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++){
        sum += 1.00 *PI * l[i]->banKinh * l[i]->banKinh;
    }
    return sum;
}

int XuatCacDuongTronDTLonHonTB(DuongTron** l, int n) {
    int dem = 0;
    float average = TongDienTich(l, n) / n;
    cout << endl << "S trung binh: " << fixed << setprecision(2) << average << endl;
    for (int i = 0; i < n; i++){
        float dientich = PI * l[i]->banKinh * l[i]->banKinh;
        if (dientich > average){
            PrintDuongTron(cout, l[i]);
            cout << " voi S=" << fixed << setprecision(2) << dientich << endl;
            dem++;
        }
    } 
    return dem;
}

void XuatDuongTronChuViGiam(DuongTron** l, int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (l[j]->banKinh < l[j+1]->banKinh){
                DuongTron *tmp = l[j];
                l[j] = l[j+1];
                l[j+1] = tmp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        float chuvi = 2.0 * PI * l[i]->banKinh;
        PrintDuongTron(cout, l[i]);
        cout << " voi P=" << fixed << setprecision(2) << chuvi;
        cout << endl;
    }
}

void XoaDsDuongTron(DuongTron** l, int n) {
    for (int i = 0; i < n; i++){
        XoaDuongTron(l[i]);
    }
    delete []l;
}