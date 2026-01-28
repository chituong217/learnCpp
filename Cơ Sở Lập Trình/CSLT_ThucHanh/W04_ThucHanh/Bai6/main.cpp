#include "Function.h"
#include <fstream>

int main(){
    const char *pathIn = "input.txt";
    ifstream fIn;
    fIn.open(pathIn);

    SNgay date1, date2;

    if (!fIn.is_open()){
        cout << "Loi mo file khong thanh cong!" << endl;
        return 1;
    }
    nhap(fIn, date1);
    nhap(fIn, date2);

    fIn.close();
    
    xuat(cout, date1);
    cout << endl;
    xuat(cout, date2);
    cout << endl;

    if (checkNamnhuan(date1)){
        cout << "Date 1 la nam nhuan" << endl;
    }
    else{
        cout << "Date 1 ko la nam nhuan" << endl;
    }

    int stt1 = tinhSTTngaytrongnam(date1);
    cout << "STT ngay trong nam cua date 1 la: " << stt1 << endl;

    long long stt2 = tinhSTTngay(date1);
    cout << "STT ngay ke tu 1/1/1 cua date 1 la: " << stt2 << endl;

    int k;
    cout << "Hay nhap vao k: ";
    cin >> k;
    SNgay date3 = tinhNgaytruocdokngay(date1, k);
    SNgay date4 = tinhNgaysaudokngay(date1, k);
    cout << "Ngay truoc date1 k ngay la: ";
    xuat(cout, date3);
    cout << endl;
    cout << "Ngay sau date1 k ngay la: ";
    xuat(cout, date4);
    cout << endl;

    if (sosanhHaingay(date1, date2) == 1){
        cout << "date1 > date2" << endl;
    }
    else if (sosanhHaingay(date1, date2) == -1){
        cout << "date 1 < date2" << endl;
    }
    else{
        cout << "date1 == date2" << endl;
    }

    return 0;
}