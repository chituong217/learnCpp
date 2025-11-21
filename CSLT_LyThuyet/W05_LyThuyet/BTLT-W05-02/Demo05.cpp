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
    ofstream f1, f2;
    
    cout << "Fraction 1: " << endl;
    inputFraction(a);
    cout << "Fraction 2: " << endl;
    inputFraction(b);
    
    f1.open("D:\\fraction1-output.txt");
    f2.open("D:\\fraction2-output.txt");
    
    if(!f1.is_open() || !f2.is_open()){
        cout << "Khong the tao hai file" << endl;
    }
    else{
        saveFraction(f1, a);
        saveFraction(f2, b);
        f1.close();
        f2.close();
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