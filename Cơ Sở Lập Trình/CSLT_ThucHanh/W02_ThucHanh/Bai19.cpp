#include <iostream>
using namespace std;

int main(){
    int instance, time, day, price;
    bool VIP;
    cout <<"Hay nhap lan luot cac thong tin sau: thoi diem su dung, thoi luong su dung(gio), thu su dung(2-8), co su dung phong VIP hay khong.\n";
    cin >> instance >> time >> day >> VIP;
    if ( day == 7 || day == 8){
        if (VIP){
            price = 400*time;
        }
        else{
            price = 200*time;
        }
    }
    else{
        if (instance >= 18){
            if(VIP){
                price = 300*time;
            }
            else{
                price = 200*time;
            }
        }
        else{
            if (VIP){
                price = 100*time;
            }
            else{
                price = 80*time;
            }
        }
    }
    cout << "So tien can phai tra la: " << price;
    return 0;
}