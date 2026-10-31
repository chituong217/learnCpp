#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    int Numerator, Denominator;

public:
    Fraction(int num = 0, int denom = 1) {
        Numerator = num;
        Denominator = denom;
        simplify();
    }

    void simplify() {
        if (Numerator == 0) {
            Denominator = 1;
            return;
        }

        if (Denominator < 0) {
            Numerator = -Numerator;
            Denominator = -Denominator;
        }

        int a = abs(Numerator);
        int b = abs(Denominator);

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }

        Numerator /= a;
        Denominator /= a;
    }

    Fraction operator+(const Fraction& other) const {
        Fraction result;

        int g = gcd(Denominator, other.Denominator);

        result.Numerator =
            Numerator * (other.Denominator / g)
            + other.Numerator * (Denominator / g);

        result.Denominator =
            (Denominator / g) * other.Denominator;

        result.simplify();
        return result;
    }

    bool operator<(const Fraction& other) const {
        return Numerator * other.Denominator
             < Denominator * other.Numerator;
    }

    void output() const {
        cout << Numerator << '/' << Denominator << '\n';
    }

    friend ostream& operator<<(
        ostream& os, const Fraction& frac
    ) {
        os << frac.Numerator << '/' << frac.Denominator;
        return os;
    }
};

class FractionArray {
private:
    vector<Fraction> v;

public:
    void loadFromFile(const string& filename) {
        ifstream fin(filename);

        v.clear();

        int num, denom;

        while (fin >> num >> denom) {
            v.push_back(Fraction(num, denom));
        }
    }

    Fraction sum() const {
        Fraction total;

        for (const Fraction& x : v) {
            total = total + x;
        }

        return total;
    }

    Fraction max() const {
        if (v.empty()) return Fraction();

        Fraction result = v[0];

        for (int i = 1; i < (int)v.size(); i++) {
            if (result < v[i]) {
                result = v[i];
            }
        }

        return result;
    }

    Fraction min() const {
        if (v.empty()) return Fraction();

        Fraction result = v[0];

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] < result) {
                result = v[i];
            }
        }

        return result;
    }

    void sortArray() {
        sort(v.begin(), v.end());
    }

    void output() const {
        for (const Fraction& x : v) {
            x.output();
        }
    }
};

int main(){
    return 0;
}