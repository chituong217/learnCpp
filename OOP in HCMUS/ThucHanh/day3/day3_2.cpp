#include <bits/stdc++.h>

using namespace std;

class Fraction{
private:
    int Numerator, Denominator;
public:
    Fraction(){
        Numerator = 0;
        Denominator = 1;
    }
    Fraction(int num, int den) : Numerator(num), Denominator(den){

    }
    void reduce(){
        if (Numerator == 0){
            Denominator = 1;
        }

        if (Denominator < 0){
            Numerator = -Numerator;
            Denominator = -Denominator;
        }

        int a = abs(Numerator), b = abs(Denominator);
        while (b){
            int r = a % b;
            a = b;
            b = r;
        }
        Numerator /= a;
        Denominator /= a;
    }

    void input(){
        cin >> Numerator >> Denominator;
        reduce();
    }
    void output(){
        cout << Numerator << '/' << Denominator;
    }

    Fraction operator + (const Fraction &other){
        Fraction moi;
        moi.Numerator = this->Numerator * other.Denominator + this->Denominator * other.Numerator;
        moi.Denominator = this->Denominator * other.Denominator;
        moi.reduce();
        return moi;
    }
    Fraction operator - (const Fraction &other){
        Fraction moi;
        moi.Numerator = this->Numerator * other.Denominator - this->Denominator * other.Numerator;
        moi.Denominator = this->Denominator * other.Denominator;
        moi.reduce();
        return moi;
    }
    Fraction operator * (const Fraction &other){
        Fraction moi;
        moi.Numerator = this->Numerator * other.Numerator;
        moi.Denominator = this->Denominator * other.Denominator;
        moi.reduce();
        return moi;
    }
    Fraction operator / (const Fraction &other){
        if (other.Numerator == 0){
            throw runtime_error("Khong the chia cho 0");
        }
        Fraction dao(other.Denominator, other.Numerator);
        return *this * dao;
    }
    int compare(Fraction other){
        if (this->Numerator*other.Denominator < this->Denominator*other.Numerator){
            return -1;
        }
        else if (this->Numerator == other.Numerator && this->Denominator == other.Denominator){
            return 0;
        }
        else{
            return 1;
        }
    }
    bool isPositive(){
        return this->Numerator > 0;
    }
    bool isNegative(){
        return this->Numerator < 0;
    }
    bool isZero(){
        return this->Numerator == 0;
    }
};

int main(){
    return 0;
}