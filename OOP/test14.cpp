#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class PhanSo{
private:
    int tu, mau;
public:
    PhanSo();
    PhanSo(int t, int m);
    void RutGon();
    
    friend istream& operator >> (istream &in, PhanSo &p);
    friend ostream& operator << (ostream &out, const PhanSo &p);
    
    PhanSo& operator ++ ();
    PhanSo& operator -- ();
    PhanSo operator ++ (int);
    PhanSo operator -- (int);
};

PhanSo::PhanSo() : tu(0), mau(1){

}

PhanSo::PhanSo(int t, int m) : tu(t), mau(m){
    if (mau == 0){
        mau = 1;
    }
}

void PhanSo::RutGon(){
    if (tu == 0){
        mau = 1;
        return;
    }
    if (mau < 0){
        tu *= -1;
        mau *= -1;
    }

    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
}

istream& operator >> (istream &in, PhanSo &p){
    do{
        in >> p.tu >> p.mau;
    } while (p.mau == 0);
    p.RutGon();

    return in;
}

ostream& operator << (ostream &out, const PhanSo &p){
    if (p.mau == 1){
        out << p.tu << endl;
    }
    else if (p.tu == 0){
        out << "0" << endl;
    }
    else{
        out << p.tu << "/" << p.mau << endl;
    }

    return out;
}

PhanSo& PhanSo::operator++(){
    tu += mau;
    RutGon();
    return *this;
}

PhanSo& PhanSo::operator--(){
    tu -= mau;
    RutGon();
    return *this;
}

PhanSo PhanSo::operator++(int){
    PhanSo temp = *this;
    ++(*this);
    return temp;
}

PhanSo PhanSo::operator--(int){
    PhanSo temp = *this;
    --(*this);
    return temp;
}

int main(){


    return 0;
}