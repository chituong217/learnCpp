// Bai tap 1.3
#include <bits/stdc++.h>

using namespace std;

class Ngay{
private:
    int d, m, y;
public:
    void Nhap();
    void Xuat();
    bool KiemTraNamNhuan();
    void NgayKeTiep();
};

void Ngay::Nhap(){
    cout << "Moi nhap ngay: ";
    cin >> d >> m >> y;
    cout << '\n';

    vector<int> ngay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->KiemTraNamNhuan() == true) ngay[1] = 29;

    while (d <= 0 || d > ngay[m - 1]){
        cout << "Ngay bi loi, moi nhap lai: ";
        cin >> d >> m >> y;
        cout << '\n';
    }
}

void Ngay::Xuat(){
    string ngay = to_string(d);
    string thang = to_string(m);
    string nam = to_string(y);

    if (ngay.size() == 1){
        ngay = '0' + ngay;
    }
    if (thang.size() == 1){
        thang = '0' + thang;
    }
    while (nam.size() < 4){
        nam = '0' + nam;
    }

    cout << ngay << '/' << thang << '/' << nam << '\n';
}

bool Ngay::KiemTraNamNhuan(){
    if ( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
        return true;
    }
    return false;
}

void Ngay::NgayKeTiep(){
    vector<int> ngay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->KiemTraNamNhuan() == true) ngay[1] = 29;

    if (m == 12){
        if (d == 31){
            d = 1;
            m = 1;
            y += 1;
        }
        else{
            d += 1;
        }
    }
    else{
        if (d == ngay[m - 1]){
            d = 1;
            m += 1;
        }
        else{
            d += 1;
        }
    }
}

int main(){
    return 0;
}