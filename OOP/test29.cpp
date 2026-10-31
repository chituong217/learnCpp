#include <bits/stdc++.h>

using namespace std;

class Fraction{
private:
    int tu, mau;
public:
    Fraction(){
        tu = 0;
        mau = 1;
    }
    Fraction(int tu, int mau){
        this->tu = tu;
        this->mau = mau;
    }
    Fraction& operator = (const Fraction &other){
        this->tu = other.tu;
        this->mau = other.mau;
        return *this;
    }
    friend ostream& operator << (ostream &out, const Fraction &x){
        if (x.mau == 0){
            out << "Loi";
        }
        else if (x.mau == 1){
            out << x.tu;
        }
        else{
            out << x.tu << '/' << x.mau;
        }
        return out;
    }
};

template <class T>
void swapT(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}


int main(){
    int a = 0, b = 1;
    Fraction x(1, 2), y(2, 3);
    swapT(a, b);
    swapT(x, y);
    cout << a << ' ' << b << endl;
    cout << x << ' ' << y << endl;
    return 0;
}