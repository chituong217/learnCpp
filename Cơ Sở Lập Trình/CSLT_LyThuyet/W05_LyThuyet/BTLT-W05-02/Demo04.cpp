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
    ifstream f;
    
    f.open("D:\\2fractions-input.txt");
    if(!f.is_open()){
        cout << "Khong the mo file" << endl;
    }
    else{
        loadFraction(f, a);
        loadFraction(f, b);
        
        cout << "Fraction a: ";
        printFraction(a);
        cout << "Fraction b: ";
        printFraction(b);
        
        f.close();
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