#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int km;
    cin >> km;
    double price=0;
    if (km == 1){
        price = 15;
    }
    else if (km <= 5){
        price = (km-1)*13.5 + 15;
    }
    else if (km <= 12){
        price = (km - 6)*11 + 5*13.5 + 15;
    }
    else{
        price = (km - 6)*11 + 5*13.5 + 15;
        price = price*90.0/100;
    }
    cout << "Gia tien la:" << price;
    return 0; 
}