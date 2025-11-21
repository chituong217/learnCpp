#include <iostream>
using namespace std;

int main(){
    int instance, day;
    cout << "Ban xem phim vao thu may: ";
    cin >> day;
    cout << "Ban xem phim vao luc may gio: ";
    cin >> instance;
    int price;
    if (day == 3){
        price = 50;
    }
    else if (day == 2 || day == 4 || day == 5){
        if (instance < 17){
            price = 60;
        }
        else{
            price = 70;
        }
    }
    else{
        if (instance < 17){
            price = 75;
        }
        else{
            price = 80;
        }
    }
    cout << "Ban can phai tra so tien la: " << price << " nghin dong.";
    return 0;
}