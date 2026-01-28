#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void loadFraction(ifstream &f, Fraction &p);
void printFraction(Fraction p);
int main(int argc, const char * argv[]) {
    Fraction a, b;
    ifstream f1, f2;
    
    f1.open("D:\\fraction1-input.txt");
    f2.open("D:\\fraction2-input.txt");
    
    if(!f1.is_open() || !f2.is_open()){
        cout << "Khong the mo hai file" << endl;
    }
    else{
        loadFraction(f1, a);
        loadFraction(f2, b);
        
        cout << "Fraction a: ";
        printFraction(a);
        cout << "Fraction b: ";
        printFraction(b);
        
        f1.close();
        f2.close();
    }
    return 0;
}

void loadFraction(ifstream &f, Fraction &p){
    f >> p.num;
    f >> p.denom;
}
void printFraction(Fraction p){
    cout << p.num << "/" << p.denom << endl;
}
