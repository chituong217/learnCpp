#include <iostream>
using namespace std;

long long factorial(int n);

int main() {
    int a = 5;
    long long S1;
    S1 = factorial(a);
    cout << S1;
    return 0;
}

long long factorial(int n) {
    long long s = 1;
    for (; n > 0; n--)
        s = s * n;
    return s;
}


