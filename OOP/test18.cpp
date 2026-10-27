
#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    void normalize() {
        if (den == 0) {
            throw invalid_argument("Mau so bang 0!");
        }

        if (den < 0) {
            num = -num;
            den = -den;
        }

        if (num == 0) {
            den = 1;
            return;
        }

        int a = abs(num);
        int b = den;

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }

        num /= a;
        den /= a;
    }

public:
    Fraction(int n = 0, int d = 1)
        : num(n), den(d) {
        normalize();
    }

    // TODO 1: Prefix ++
    // Fraction& operator++()
    Fraction& operator++ (){
        num += den;
        normalize();
        return *this;
    }

    // TODO 2: Postfix ++
    // Fraction operator++(int)
    Fraction operator ++ (int){
        Fraction old = *this;
        (++*this);
        return old;
    }

    friend ostream& operator<<(ostream& out,
                               const Fraction& f) {
        return out << f.num << "/" << f.den;
    }
};

int main() {
    Fraction a(2, 3);

    Fraction old = a++;

    cout << "old = " << old << endl;
    cout << "a = " << a << endl;

    ++a;
    cout << "a sau prefix = " << a << endl;

    return 0;
}
