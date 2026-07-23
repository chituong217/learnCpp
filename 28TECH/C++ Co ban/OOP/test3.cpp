#include <bits/stdc++.h>

using namespace std;

class ThiSinh{
private:
    string hoten, ngaysinh;
    double diem1, diem2, diem3;

public:
    friend istream& operator >> (istream &in, ThiSinh &x){
        getline(in, x.hoten);
        in >> x.ngaysinh >> x.diem1 >> x.diem2 >> x.diem3;
        return in;
    }

    friend ostream& operator << (ostream &out, ThiSinh x){
        out << x.hoten << " " << x.ngaysinh << " " << fixed << setprecision(1) << (x.diem1 + x.diem2 + x.diem3) << endl;
        return out;
    }

    bool operator < (ThiSinh khac){
        return (this->diem1 + this->diem2 + this->diem3) < (khac.diem1 + khac.diem2 + khac.diem3);
    }
};

int main(){
    ThiSinh x;
    cin >> x;
    cout << x;

    return 0;
}