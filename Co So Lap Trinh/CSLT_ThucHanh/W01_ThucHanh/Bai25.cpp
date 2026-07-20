#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double km, hour, minute, second;
    cin >> km >> hour >> minute >> second;
    double pace = (minute + hour*60 + second/60) / (km);
    double speed = (km) / (hour + minute/60 + second/3600);
    cout << fixed << setprecision(2) << speed << " " << pace;
    return 0;
}