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

class Fraction{
private:
    int tu, mau;
public:
    Fraction(){
        tu = 0;
        mau = 1;
    }
    Fraction(int t, int m) : tu(t), mau(m){
        if (mau == 0){
            mau = 1;
        }
        RutGon();
    }
    void RutGon();
    Fraction operator + (const Fraction &other){
        Fraction moi;
        moi.tu = this->tu * other.mau + other.tu * this->mau;
        moi.mau = this->mau * other.mau;
        moi.RutGon();
        return moi;
    }
    Fraction operator + (int x) const{
        Fraction moi;
        moi.tu = this->tu + x * this->mau;
        moi.mau = this->mau;
        moi.RutGon();
        return moi;
    }
    friend Fraction operator + (int a, const Fraction &other){
        return (other + a).RutGon();
    }
    Fraction operator - (const Fraction &other){
        Fraction moi;
        moi.tu = this->tu * other.mau - other.tu * this->mau;
        moi.mau = this->mau * other.mau;
        moi.RutGon();
        return moi;
    }
    Fraction operator * (const Fraction &other){
        Fraction moi;
        moi.tu = this->tu * other.tu;
        moi.mau = this->mau * other.mau;
        moi.RutGon();
        return moi;
    }
    Fraction operator / (const Fraction &other){
        Fraction otherNghichDao;
        otherNghichDao.tu = other.mau;
        otherNghichDao.mau = other.tu;

        return ((*this) * otherNghichDao).RutGon();
    }
    void Xuat() const{
        if (tu == 0){
            cout << "0" << endl;
        }
        else if (mau == 1){
            cout << tu << endl;
        }
        else{
            cout << tu << '/' << mau << endl;
        }
    }
    void Nhap(){
        cin >> this->tu >> this->mau;
        RutGon();
    }


    Fraction& operator ++ (){
        tu += mau;
        RutGon();
        return *this;
    }
    Fraction operator ++ (int){
        Fraction moi = (*this);
        ++(*this);
        return moi;
    }
};

void Fraction::RutGon(){
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

int main(){
    Fraction x, y;
    x.Nhap();

    x.Xuat();
    y = x + 5;
    y.Xuat();
    y = 5 + x;
    y.Xuat();

    return 0;
}