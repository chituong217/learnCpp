#include <bits/stdc++.h>

using namespace std;

long long ucln(long long a, long long b);
long long bcnn(long long a, long long b);


class PS{
private:
    long long tu, mau;
public:
    friend istream& operator >> (istream& in, PS &x){
        in >> x.tu >> x.mau;

        return in;
    }
    friend ostream& operator << (ostream& out, PS x){
        out << x.tu << '/' << x.mau;
        
        return out;
    }

    void rutgon();

    PS operator + (PS khac){
        PS C;
        C.mau = this->mau * khac.mau;
        C.tu = (this->tu * khac.mau + khac.tu * this->mau);

        return C;
    }
    PS operator * (PS khac){
        PS C;
        C.tu = this->tu * khac.tu;
        C.mau = this->mau * khac.mau;

        return C;
    }

    void binhphuong();
};

long long ucln(long long a, long long b){
    while (b){
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long bcnn(long long a, long long b){
    return (a * b) / ucln(a, b);
}

void PS::rutgon(){
    long long u = ucln(tu, mau);
    tu /= u;
    mau /= u;
}

void PS::binhphuong(){
    this->tu *= this->tu;
    this->mau *= this->mau;
}

int main(){
    int t;
    cin >> t;
    
    while (t--){
        PS A, B;
        cin >> A >> B;
        PS C = (A + B);
        C.binhphuong();

        PS D = A * B * C;

        C.rutgon(); D.rutgon();

        cout << C << ' ' << D << '\n';
    }

    return 0;
}