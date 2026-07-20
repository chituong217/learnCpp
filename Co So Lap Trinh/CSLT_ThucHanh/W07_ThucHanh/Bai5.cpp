#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

struct SNgay {
    int d;
    int m;
    int y;
};

bool checkNamNhuan(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int tinhSTTNgayTrongNam(const SNgay* date) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (checkNamNhuan(date->y)) {
        daysInMonth[2] = 29;
    }
    int stt = date->d;
    for (int i = 1; i < date->m; i++) {
        stt += daysInMonth[i];
    }
    return stt;
}

long long tinhTongSoNgay(const SNgay* date) {
    long long stt = (1ll * (date->y - 1) / 400) * (97 * 366 + 303 * 365);
    int soNam = (date->y - 1) % 400;
    for (int i = 1; i <= soNam; i++) {
        if (checkNamNhuan(i)) {
            stt += 366;
        } else {
            stt += 365;
        }
    }
    stt += tinhSTTNgayTrongNam(date);
    return stt;
}

void nhapNgay(SNgay* date) {
    cout << "Nhap ngay, thang, nam: ";
    cin >> date->d >> date->m >> date->y;
}

void xuatNgay(const SNgay* date) {
    cout << date->d << "/" << date->m << "/" << date->y;
}

long long tinhKhoangCach(const SNgay* date1, const SNgay* date2) {
    long long stt1 = tinhTongSoNgay(date1);
    long long stt2 = tinhTongSoNgay(date2);
    return abs(stt1 - stt2);
}

int main() {
    SNgay* date1 = new SNgay;
    SNgay* date2 = new SNgay;

    cout << "Nhap thong tin ngay thu 1:" << endl;
    nhapNgay(date1);

    cout << "Nhap thong tin ngay thu 2:" << endl;
    nhapNgay(date2);

    cout << endl << "Thong tin ngay da nhap:" << endl;
    cout << "Date 1: ";
    xuatNgay(date1);
    cout << endl << "Date 2: ";
    xuatNgay(date2);
    cout << endl;

    long long khoangCach = tinhKhoangCach(date1, date2);
    cout << endl << "Khoang cach giua 2 ngay la: " << khoangCach << " ngay." << endl;

    delete date1;
    delete date2;

    return 0;
}