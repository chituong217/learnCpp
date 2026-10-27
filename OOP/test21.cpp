
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    void normalize() {
        // TODO 1: Kiem tra mau so bang 0.
        if (den == 0){
            throw invalid_argument("Mau so bang 0!");
        }
        // TODO 2: Dua dau am ve tu so.
        if (den < 0){
            num = -num;
            den = -den;
        }
        // TODO 3: Rut gon phan so.
        int a = abs(num), b = abs(den);
        while (b){
            int r = a % b;
            a = b;
            b = r;
        }
        num /= a;
        den /= a;
        // TODO 4: Bieu dien so 0 thanh 0/1.
        if (num == 0){
            num = 0;
            den = 1;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        normalize();
    }

    // TODO 5: Khai bao friend operator<<
    friend ostream& operator << (ostream &out, const Fraction &x);
    // TODO 6: Khai bao friend operator>>
    friend istream& operator >> (istream &in, Fraction &x);
};

// TODO 7: Dinh nghia operator<<
ostream& operator << (ostream &out, const Fraction &x){
    if (x.den == 1){
        out << x.num;
    }
    else{
        out << x.num << '/' << x.den;
    }
    return out;   
}

// TODO 8: Dinh nghia operator>>
istream& operator >> (istream &in, Fraction &x){
    int n, d;
    char slash;
    if (!(in >> n >> slash >> d)) {
        return in;
    }

    if (slash != '/' || d == 0) {
        in.setstate(ios::failbit);
    }
    else{
        x = Fraction(n, d);
    }
    
    return in;
}

int main() {
    Fraction a(2, 4);
    Fraction b;

    cout << "a = " << a << endl;

    cout << "Nhap phan so b (vi du 3/5): ";
    if (cin >> b) {
        cout << "b = " << b << endl;
    } else {
        cout << "Du lieu khong hop le!" << endl;
    }

    return 0;
}
