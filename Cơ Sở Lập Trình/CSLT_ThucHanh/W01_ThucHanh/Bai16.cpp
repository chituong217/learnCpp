#include <iostream>
using namespace std;

int main(){
    int plate;
    cin >> plate;
    int nut = 0;
    while (plate){
        nut += plate %10;
        plate /= 10;
    }
    nut %= 10;
    cout << nut;
    return 0;
}