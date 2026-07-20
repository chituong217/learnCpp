#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a == 0){
        cout<< "Invalid value!";
    }
    else {
        double x = -1.00*b / a;
        cout << "Nghiem cua phuong trinh la:" << x;
    }
    return 0;
}