#include <iostream>
using namespace std;

int main(){
    int money;
    cin >> money;
    cout << "500000: " << money/500000<< endl;
    money %= 500000;
    cout << "200000: " << money/200000<< endl;
    money %= 200000;
    cout << "100000: " << money/100000<< endl;
    money %= 100000;
    cout << "50000: " << money/50000<< endl;
    money %= 50000;
    cout << "20000: " << money/20000<< endl;
    money %= 20000;
    cout << "10000: " << money/10000<< endl;
    money %= 10000;
    cout << "5000: " << money/5000<< endl;
    money %= 5000;
    cout << "2000: " << money/2000<< endl;
    money %= 2000;
    cout << "1000: " << money/1000<< endl;
    money%= 1000;
    return 0;
}