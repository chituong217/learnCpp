#include <bits/stdc++.h>

using namespace std;

class Fraction{
private:
    int num, den;
public:
    Fraction();
    Fraction(int num, int den);
    string to_string();
};

Fraction::Fraction() : num(0), den(1){

}

Fraction::Fraction(int num, int den){
    this->num = num;
    this->den = den;
}

string Fraction::to_string(){
    return std::to_string(num) + "/" + std::to_string(den);
}

#include "main.h"