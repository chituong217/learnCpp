#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0){
        cout << "Khong phai phuong trinh bac hai!";
    }
    else{
        double delta = b*b - 4*a*c;
        if (delta == 0){
            double x = (-b/(2*a));
            cout << "Phuong trinh co nghiem kep x=" << x;
        }
        else if (delta > 0){
            double x1 = (-b- sqrt(delta)) / (2*a);
            double x2 = (-b+ sqrt(delta)) / (2*a);
            cout << "Phuong trinh co 2 nghiem phan biet :\n x1=" << x1 << "\nx2=" <<x2;
        }
        else{
            cout << "Pt vo nghiem";
        }
    }

    return 0;
}