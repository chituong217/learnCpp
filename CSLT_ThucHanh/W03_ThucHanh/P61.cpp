#include <iostream>
using namespace std;

int ucln(int a, int b){
    while (b){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << (a*b)/ucln(a, b);
    return 0;
}