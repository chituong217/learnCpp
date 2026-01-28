#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int smaller = fmin(a, b);
    cout << smaller << endl;
    return 0;
}