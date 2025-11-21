#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    int a, b;
    cin >> a >> b;
    double c = 1.00*a/b;
    cout <<a << " / "<<b<<" = "<< fixed<< setprecision(2)<< c;
    return 0;
}