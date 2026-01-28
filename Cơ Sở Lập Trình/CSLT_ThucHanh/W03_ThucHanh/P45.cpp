#include <iostream>
using namespace std;

long long tich(int n){
    long long tich = 1;
    while (n){
        tich *= n;
        n--;
    }
    return tich;
}

int main(){
    int n;
    cin >> n;
    cout << tich(n);
    return 0;
}