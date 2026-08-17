#include <bits/stdc++.h>

using namespace std;

class PhanSo{
private:
    int tuso, mauso;
public:
    void rutgon();

    PhanSo(){
        tuso = 0;
        mauso = 1;
    }

    PhanSo (int tu, int mau){
        tuso = tu;
        mauso = mau;

        if (mauso == 0) mauso = 1;
        rutgon();
    }

    PhanSo operator + (const PhanSo &moi){
        PhanSo p;
        p.tuso = this->tuso * moi.mauso + this->mauso * moi.tuso;
        p.mauso = this->mauso * moi.mauso;
        p.rutgon();

        return p;
    }

    PhanSo operator - (const PhanSo &moi){
        PhanSo p;
        p.tuso = this->tuso * moi.mauso - this->mauso * moi.tuso;
        p.mauso = this->mauso * moi.mauso;
        p.rutgon();

        return p;
    }

    bool operator == (const PhanSo &moi){
        if (this->tuso == moi.tuso && this->mauso == moi.mauso) return true;
        return false;
    }

    friend istream& operator >> (istream &in, PhanSo &p){
        in >> p.tuso >> p.mauso;
        if (p.mauso == 0) p.mauso = 1;
        p.rutgon();

        return in;
    }

    friend ostream& operator << (ostream &out, const PhanSo &p){
        out << p.tuso << '/' << p.mauso;
        
        return out;
    }
};

int ucln(int a, int b){
    while (b){
        int r = a % b;
        a = b; 
        b = r;
    }
    return a;
}

void PhanSo::rutgon(){
    if (mauso < 0){
        tuso = -tuso;
        mauso = -mauso;
    }

    int u = ucln(abs(tuso), abs(mauso));
    tuso /= u;
    mauso /= u;
}

int main(){
    PhanSo p1, p2;
    cin >> p1 >> p2;

    cout << p1 + p2 << endl;
    cout << p1 - p2 << endl;

    if (p1 == p2){
        cout << p1 << " == " << p2 << endl;
    }
    else{
        cout << p1 << " != " << p2 << endl;
    }

    return 0;
}
