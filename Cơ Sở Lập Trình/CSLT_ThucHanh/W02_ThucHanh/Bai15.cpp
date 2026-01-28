#include <iostream>
using namespace std;

int checkNamNhuan(int n){
    if (n%400 == 0 || (n%4==0 && n%100 !=0)){
        return 1;
    }
    return 0;
}

int main(){
    int m, y, d;
    cin >> m >> y;
    if (m == 2){
        if (checkNamNhuan(y) == 1){
            d = 29;
        }
        else{
            d = 28;
        }
    }
    else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        d = 31;
    }
    else{
        d = 30;
    }
    cout << "Co " << d << " ngay.";
    return 0;
}