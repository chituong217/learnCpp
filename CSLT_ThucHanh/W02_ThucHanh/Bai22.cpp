#include <iostream>
using namespace std;

int main(){
    int oldW, newW;
    cin >> oldW >> newW;
    int W = newW - oldW;
    long long price;
    if (W <= 4){
        price = W*3300;
    }
    else if (W <= 6){
        price = (W-4)*5200 + 4*3300;
    }
    else{
        price = (W-6)*7000 + 2*5200 + 4*3300;
    }
    price = (1.00*price*110)/100;
    cout << "So tien can tra la " << price << " VND.";
    return 0;
}