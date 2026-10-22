#include "day2_4.h"

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Fraction::Fraction(){
    num = 0;
    den = 1;
}
Fraction::Fraction(int num, int den){
    this->num = num;
    this->den = den;
}

string Fraction::to_string(){
    return std::to_string(num) + "/" + std::to_string(den);
}

Fraction Fraction::add(Fraction other){
    Fraction moi;
    moi.num = this->num * other.den + this->den * other.num;
    moi.den = this->den * other.den;
    moi.simplify();
    return moi;
}

Fraction Fraction::subtract(Fraction other){
    Fraction moi;
    moi.num = this->num * other.den - this->den * other.num;
    moi.den = this->den * other.den;
    moi.simplify();
    return moi;
}

Fraction Fraction::multiply(Fraction other){
    Fraction moi;
    moi.num = this->num * other.num;
    moi.den = this->den * other.den;
    moi.simplify();
    return moi;
}

Fraction Fraction::divide(Fraction other){
    Fraction moi;
    moi.num = this->num * other.den;
    moi.den = this->den * other.num;
    moi.simplify();
    return moi;
}

void Fraction::simplify(){
    int ucln = gcd(num, den);

    if(ucln == 0) return;

    this->num /= ucln;
    this->den /= ucln;

    if(den < 0){
        num = -num;
        den = -den;
    }
}

int Fraction::getNumerator(){
    return num;
}

int Fraction::getDenominator(){
    return den;
}

void Fraction::setNumerator(int num){
    this->num = num;
}

void Fraction::setDenominator(int den){
    this->den = den;
}