#include <iostream>
using namespace std;

long long findFirstDigit(int n){
    long long first = 0;
    while (n>0){
        first = n%10;
        n/=10;
    }
    return first;
}

int main(){
    int n;
    cin >> n;
    cout << findFirstDigit(n);
    return 0;
}