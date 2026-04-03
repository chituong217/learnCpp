#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
    while (b){
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

struct PhanSo{
    ll tu, mau;

    void RutGon(){
        ll uc = gcd(this->tu, this->mau);
        this->tu /= uc;
        this->mau /= uc;
    }
    PhanSo operator - (PhanSo b){
        ll mauChung = this->mau * b.mau;
        ll tu1 = this->tu * b.mau - this->mau * b.tu;
        PhanSo res{tu1, mauChung};
        res.RutGon();
        return res;
    }
};  

int main(){
    PhanSo a;
    cin >> a.tu >> a.mau;
    
    while(a.tu != 0){
        ll x;
        if (a.mau % a.tu == 0){
            x = a.mau / a.tu;
        }
        else{
            x = a.mau / a.tu + 1;
        }

        PhanSo res{1, x};
        cout << "1" << "/" << x;
        a = a - res;
        if (a.tu != 0){
            cout << " + ";
        }
    }

    return 0;
}