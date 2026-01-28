#include "Function.h"

#include <fstream>

int main(){
    const char *pathIn = "input.txt";
    ifstream fIn;
    SDonThuc dt1, dt2;

    fIn.open(pathIn);

    if (!fIn.is_open()){
        cout << "Khong the mo file" << endl;
        return 1;
    }

    nhapDonThuc(fIn, dt1);
    nhapDonThuc(fIn, dt2);

    fIn.close();

    cout << "Don thuc 1: ";
    xuatDonThuc(cout, dt1);
    cout << endl;

    cout << "Don thuc 2: ";
    xuatDonThuc(cout, dt2);
    cout << endl;

    // Tích của 2 đơn thức
    SDonThuc tich = tichDonThuc(dt1, dt2);
    cout << "Tich (dt1 * dt2) = ";
    xuatDonThuc(cout, tich);
    cout << endl;

    // Thương của 2 đơn thức
    SDonThuc thuong = thuongDonThuc(dt1, dt2);
    cout << "Thuong (dt1 / dt2) = ";
    xuatDonThuc(cout, thuong);
    cout << endl;

    // Đạo hàm cấp 1
    SDonThuc dh1 = DaoHamCap1(dt1);
    cout << "Dao ham cap 1 (dt1)' = ";
    xuatDonThuc(cout, dh1);
    cout << endl;

    // Đạo hàm cấp k
    int k;
    cout << "Nhap bac k cua dao ham: ";
    cin >> k;
    SDonThuc dhk = DaoHamCapK(dt1, k);
    cout << "Dao ham cap " << k << " (dt1) = ";
    xuatDonThuc(cout, dhk);
    cout << endl;

    // Tính giá trị
    double x0;
    cout << "Nhap gia tri x0: ";
    cin >> x0;
    double giatri = tinhGiaTri(dt1, x0);
    cout << "Gia tri dt1 tai x = " << x0 << " la: " << giatri << endl;

    return 0;
}