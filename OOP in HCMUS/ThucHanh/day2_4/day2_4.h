#ifndef FRACTION
#define FRACTION

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b);

class Fraction{
private:
    int num, den;
public:
    Fraction();
    Fraction(int num, int den);
    string to_string();
    Fraction add(Fraction other);
    Fraction subtract(Fraction other);
    Fraction multiply(Fraction other);
    Fraction divide(Fraction other);
    void simplify();
    int getNumerator();
    int getDenominator();
    void setNumerator(int num);
    void setDenominator(int den);
};

#endif