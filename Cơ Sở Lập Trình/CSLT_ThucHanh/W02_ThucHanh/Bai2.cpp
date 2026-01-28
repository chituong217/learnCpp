#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int bigger = fmax(a, b);
    cout << bigger << endl;
    return 0;
}