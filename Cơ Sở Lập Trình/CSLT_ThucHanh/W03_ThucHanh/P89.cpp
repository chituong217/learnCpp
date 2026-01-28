#include <iostream>
using namespace std;

int mod(int a, int b){
    while (a >= b){
        a-=b;
    }
    return a;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << mod(a, b);
    return 0;
}