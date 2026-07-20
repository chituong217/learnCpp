#include <iostream>
using namespace std;

int ucln(int a, int b){
    while (b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int gcd = ucln(ucln(a, b), c);
    cout << gcd;
    return 0;
}