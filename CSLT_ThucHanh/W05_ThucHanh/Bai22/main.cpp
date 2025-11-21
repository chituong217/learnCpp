#include "Function.h"
#include <fstream>
#define MAX_LEN 100

int main(){
    PhanSo a[MAX_LEN];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        nhapPhanSo(cin, a[i]);
    }

    for (int i=0; i<n; i++){
        rutgonPhanSo(a[i]);
    }

    // Đếm số lượng pso âm dương
    int soAm=0, soDuong=0;
    for (int i=0; i<n; i++){
        if (checkAmDuong(a[i]) == 1){
            soDuong++;
        }
        else{
            soAm++;
        }
    }
    cout << "So luong phan so am: " << soAm << endl;
    cout << "So luong phan so duong: " << soDuong << endl;

    // xuất số dương đầu tiên
    for (int i=0; i<n; i++){
        if (checkAmDuong(a[i]) == 1){
            cout << "Phan so duong dau tien xuat hien trong mang: ";
            xuatPhanSo(a[i]);
            break;
        }
    }

    // Tìm số nhỏ nhất / lớn nhất
    PhanSo psMIN, psMAX;
    psMIN.tu = 1e9; psMIN.mau = 1; psMAX.tu = -1e9; psMAX.mau = 1;
    for (int i=0; i<n; i++){
        if ( sosanhPhanSo(a[i], psMAX) >= 0){
            psMAX = a[i];
        }
        if (sosanhPhanSo(a[i], psMIN) <= 0){
            psMIN = a[i];
        }
    }
    cout << "Phan so max: "; xuatPhanSo(psMAX);
    cout << "Phan so min: "; xuatPhanSo(psMIN);

    // Sap xep mang giam dan
    sort(a, n);
    for (int i=0; i<n; i++){
        xuatPhanSo(a[i]);
    }

    return 0;
}