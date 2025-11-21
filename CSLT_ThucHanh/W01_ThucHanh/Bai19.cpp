#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    a = a + b;
    b = a - b;
    a = a - b;

    b = b + c;
    c = b - c;
    b = b - c;
    cout << a << " " << b << " " << c;
    return 0;
}