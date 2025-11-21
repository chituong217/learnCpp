#include <iostream>
using namespace std;

int main(){
    int oldE, newE;
    cin >> oldE >> newE;
    int E = newE - oldE;
    long long price;
    if (E <= 50){
        price = E*1484;
    }
    else if ( E <= 100){
        price = (E-50)*1533 + 50*1484;
    }
    else if( E <= 200){
        price = (E-100)*1786 + 50*1484 + 50*1533;
    }
    else if (E <= 300){
        price = (E-200)*2242 + 100*1786 + 50*1484 + 50*1533;
    }
    else if (E <= 400){
        price = (E-300)*2503 + 100*2242 + 100*1786 + 50*1484 + 50*1533;
    }
    else{
        price = (E-400)*2587 + 100*2503 + 100*2242 + 100*1786 + 50*1484 + 50*1533;
    }
    price = (price*1.00*110)/100;
    cout << "Ban can tra " << price << " VND.";
    return 0;
}