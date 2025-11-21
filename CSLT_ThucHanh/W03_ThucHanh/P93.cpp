#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long res = 1;
    n++;
    while (n){
        res *= n;
        n--;
    }
    res -=1;
    cout << res;
    return 0;
}