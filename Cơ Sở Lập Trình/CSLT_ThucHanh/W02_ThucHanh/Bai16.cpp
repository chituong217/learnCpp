#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a+b>c || b+c>a || a+c>b){
        if ( a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
            if (a == b || b == c || a == c){
                cout << "Tam giac vuong can.";
            }
            else{
                cout << "Tam giac vuong.";
            }
        }
        else if (a==b && b==c){
            cout << "Tam giac deu.";
        }
        else if (a==b || b==c || c==a){
            cout << "Tam giac can.";
        }
        else{
            cout << "Tam giac thuong.";
        }
    }
    else{
        cout << "Khong phai la tam giac.";
    }
    return 0;
}