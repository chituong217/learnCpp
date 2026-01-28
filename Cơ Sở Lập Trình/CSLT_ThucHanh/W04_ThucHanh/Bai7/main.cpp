#include "Function.h"
#include <fstream>

int main(){
    const char *pathIn = "input.txt";
    ifstream fIn;

    fIn.open(pathIn);
    SSinhVien sv1, sv2;
    if (!fIn.is_open()){
        cout << "Khong the mo file" << endl;
        return 1;
    }

    nhap(fIn, sv1);
    nhap(fIn, sv2);
    fIn.close();

    xuat(cout, sv1);
    xuat(cout, sv2);

    int age1 = tinhTuoi(sv1);
    cout << "Tuoi cua sinh vien 1 la: " << age1 << endl;

    int ssName = sosanhTen(sv1, sv2);
    if (ssName == -1){
        cout << "Sv1 dung truoc" << endl;
    }
    else if (ssName == 0){
        cout << "Trung ten" << endl;
    }
    else{
        cout << "Sv2 dung truoc" << endl;
    }

    int ssAge = sosanhTuoi(sv1, sv2);
    if (ssAge < 0){
        cout << "Sv1 nho tuoi hon" << endl;
    }
    else if (ssAge == 0){
        cout << "Trung tuoi" << endl;
    }
    else{
        cout << "Sv2 nho tuoi hon" << endl;
    }

    return 0;
}
