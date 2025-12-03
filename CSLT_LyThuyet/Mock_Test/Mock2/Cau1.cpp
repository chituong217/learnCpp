#include <iostream>

using namespace std;

int sumEvenDigits(int n){
    if (n < 10){
        if (n % 2 == 0){
            return n;
        }
        else{
            return 0;
        }
    }
    if ((n % 10) % 2 == 0){
        return (n % 10) + sumEvenDigits(n / 10);
    }
    else{
        return sumEvenDigits(n / 10);
    }
}

int main(){
    int n;
    cin >> n;
    cout << sumEvenDigits(n);
    return 0;
}