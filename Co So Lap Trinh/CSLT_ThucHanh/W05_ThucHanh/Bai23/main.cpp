#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#define MAX_LEN 100

using namespace std;

struct SDiem{
    double x;
    double y;
};

void nhapDiem(istream &fIn, SDiem &d);

void xuatDiem(ostream &Fout, SDiem d);

double tinhKhoangCach(SDiem d1, SDiem d2);

int main(){
    int n;
    cin >> n;
    SDiem a[MAX_LEN];
    for (int i=0; i<n; i++){
        nhapDiem(cin, a[i]);
    }

    //Đếm số điểm có hoàng độ dương
    int cntDuong = 0;
    for (int i=0; i<n; i++){
        if (a[i].x > 0){
            cntDuong++;
        }
    }
    cout << "So diem co hoang do duong la: " << cntDuong << endl;

    // Dem so diem khong trung nhau trong mang
    int cntKoTrung = 0;
    for (int i=0; i<n; i++){
        int check = 1;
        for (int j=0; j < i; j++){
            if (a[i].x == a[j].x && a[i].y == a[j].y){
                check = 0;
                break;
            }
        }
        if (check == 1) cntKoTrung++;
    }
    cout << "So cac diem khong trung nhau la: " << cntKoTrung << endl;

    // Tim diem co hoanh do lon nhat
    SDiem xmax; xmax.x = -1e9;
    for (int i=0; i<n; i++){
        if (a[i].x > xmax.x){
            xmax = a[i];
        }
    }
    cout << "Diem co hoanh do lon nhat la: "; xuatDiem(cout, xmax);

    // Tim diem gan goc toa do nhat
    SDiem gan; gan.x = 1e9; gan.y = 1e9;
    SDiem goc; goc.x = 0; goc.y = 0;
    for (int i=0; i<n; i++){
        double tmp = tinhKhoangCach(a[i], goc);
        if (tmp < tinhKhoangCach(goc, gan)){
            gan = a[i];
        }
    }
    cout << "Diem gan goc toa do nhat la: "; xuatDiem(cout, gan);


    return 0;
}

void nhapDiem(istream &in, SDiem &d){
    in >> d.x;
    in >> d.y;
}

void xuatDiem(ostream &out, SDiem d){
    out << "(" << d.x << ";" << d.y << ")" << endl;
}

double tinhKhoangCach(SDiem d1, SDiem d2){
    double dx = d1.x - d2.x;
    double dy = d1.y - d2.y;
    return sqrt(dx * dx + dy * dy);
}

