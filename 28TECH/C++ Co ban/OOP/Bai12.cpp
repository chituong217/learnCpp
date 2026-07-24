#include <bits/stdc++.h>

using namespace std;

class TS{
private:
    string makv, hoten;
    double diem1, diem2, diem3;

    int khuvuc;
    double tongdiem;
    string tthai;
public:
    friend istream& operator >> (istream &in, TS &x){
        getline(in, x.makv);
        getline(in, x.hoten);
        in >> x.diem1 >> x.diem2 >> x.diem3;

        return in;
    }

    friend ostream& operator << (ostream &out, TS x){
        out << x.makv << " " << x.hoten << " " << x.khuvuc << " ";
        int score10 = round(x.tongdiem * 10);
        if (score10 % 10 == 0){
            out << score10 / 10;
        }
        else{
            out << fixed << setprecision(1) << x.tongdiem;
        }

        out << " " << x.tthai << endl;

        return out;
    }

    void findKhuVuc();
    void tinhDiem();
    void xetTuyen();
};

void TS::findKhuVuc(){
    this->khuvuc = (this->makv[2] - '0');
}

void TS::tinhDiem(){
    this->tongdiem = diem1 + diem2 + diem3;

    if (khuvuc == 1){
        tongdiem += 0.5;
    }
    else if (khuvuc == 2){
        tongdiem += 1.0;
    }
    else if (khuvuc == 3){
        tongdiem += 2.5;
    }
}

void TS::xetTuyen(){
    if (tongdiem >= 24){
        tthai = "TRUNG TUYEN";
    }
    else{
        tthai = "TRUOT";
    }
}

int main(){
    TS x;
    cin >> x;
    x.findKhuVuc();
    x.tinhDiem();
    x.xetTuyen();
    cout << x;

    return 0;
}