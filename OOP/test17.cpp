#include <iostream>
using namespace std;

class Fraction {
private:
    int num;
    int den;

public:
    Fraction(int n, int d) {
        num = n;
        den = d;
    }

    // TODO 1: Khai bao friend operator<<
    friend ostream& operator << (ostream &out, const Fraction &x);
};

// TODO 2: Dinh nghia operator<< o ngoai class
ostream& operator << (ostream &out, const Fraction &x){
    if (x.den == 0){
        out << "Phan so vo dinh !";
    }
    else if (x.den == 1){
        out << x.num;
    }
    else{
        out << x.num << '/' << x.den;
    }
    return out;
}

int main() {
    Fraction a(3, 4);
    Fraction b(5, 7);

    cout << a << endl;
    cout << b << endl;
    cout << "Phan so a: " << a << ", phan so b: " << b << endl;
    
    return 0;
}
