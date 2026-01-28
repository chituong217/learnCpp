#include <iostream>
using namespace std;

int main(){
    bool dangki;
    int kB;
    cout << "Nguoi dung co dang ki goi MIU khong? (nhap vao 0 hoac 1).";
    cin >> dangki;
    if (dangki == 1){
        cout << "Nguoi dung can tra 70k.";
    }
    else{
        cout << "Hay nhap vao dung luong 3G da su dung tinh theo KB:";
        cin >> kB;
        int price = (kB/50) * 75;
        cout << "Nguoi dung can tra " << price;
    }
    return 0;
}