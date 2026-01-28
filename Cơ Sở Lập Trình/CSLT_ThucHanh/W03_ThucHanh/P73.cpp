#include <iostream>
using namespace std;

int tinhSoNgay(int d, int m, int y){
    int cnt = 0;
    int soNamNhuan = y/4 + y/400 - y/100;
    cnt += soNamNhuan*366 + (y-soNamNhuan)*365;
    for (int i = 1; i <= m; i++){
        if (i == m){
            break;
        }
        else{
            if (i == 2){
                if (y%400 == 0 || (y%4==0 && y%100 !=0)){
                    cnt += 29;
                }
                else{
                    cnt += 28;
                }
            }
            else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
                cnt += 31;
            }
            else{
                cnt += 30;
            }
        }
    }
    cnt += d;
    return cnt;
}

int main(){
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    int cnt = tinhSoNgay(d2, m2, y2) - tinhSoNgay(d1, m1, y1) ;
    cout << cnt;
    return 0;
}