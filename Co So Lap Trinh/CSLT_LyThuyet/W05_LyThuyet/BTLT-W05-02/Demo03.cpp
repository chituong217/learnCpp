#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void inputFraction(Fraction &p);
void saveFraction(ofstream &f, Fraction p);

int main(int argc, const char * argv[]) {
    Fraction a, b;
    ofstream f;
    
    cout << "Fraction 1: " << endl;
    inputFraction(a);
    cout << "Fraction 2: " << endl;
    inputFraction(b);
    
    f.open("D:\\2fractions-output.txt");
    if(!f.is_open()){
        cout << "Khong the tao file" << endl;
    }
    else{
        saveFraction(f, a);
        saveFraction(f, b);
        f.close();
    }
    return 0;
}

void inputFraction(Fraction &p){
    cout << "Numerator: ";
    cin >> p.num;
    cout << "Denominator: ";
    cin >> p.denom;
}
void saveFraction(ofstream &f, Fraction p){
    f << p.num << " " << p.denom << endl;
}