#include "Function.h"
#include <fstream>

int main(){

    const char *pathIn = "input.txt";
    PhanSo ps1, ps2;
    ifstream fIn;
    fIn.open(pathIn);

    nhapPhanSo(fIn, ps1);
    nhapPhanSo(fIn, ps2);

    fIn.close();
    
    PhanSo tong;
    tong = congPhanSo(ps1, ps2);
    rutgonPhanSo(tong);
    cout << "Tong cua hai phan so ban vua nhap la :" << endl;
    xuatPhanSo(tong);

    PhanSo hieu;
    hieu = hieuPhanSo(ps1, ps2);
    rutgonPhanSo(hieu);
    cout << "Hieu cua hai phan so ban vua nhap la :" << endl;
    xuatPhanSo(hieu);

    PhanSo tich;
    tich = tichPhanSo(ps1, ps2);
    rutgonPhanSo(tich);
    cout << "Tich cua hai phan so ban vua nhap la :" << endl;
    xuatPhanSo(tich);

    PhanSo thuong;
    thuong = thuongPhanSo(ps1, ps2);
    rutgonPhanSo(thuong);
    cout << "Thuong cua hai phan so ban vua nhap la :" << endl;
    xuatPhanSo(thuong);

    
    int check = checkToiGian(ps1);
    if (check == 1){
        cout << "Phan so 1 toi gian" << endl;
    }
    else{
        cout << "Phan so 1 chua toi gian" << endl;
    }

    check = checkAmDuong(ps2);
    if (check == 1){
        cout << "Phan so 2 la duong" << endl;
    }
    else{
        cout << "Phan so 2 la am" << endl;
    }

    check = sosanhPhanSo(ps1, ps2);
    if (check == 1){
        cout << "Phan so 1 lon hon phan so 2" << endl;
    }
    else if (check == 0){
        cout << "Phan so 1 bang phan so 2" << endl;
    }
    else{
        cout << "Phan so 1 be hon phan so 2" << endl;
    }

    return 0;
}