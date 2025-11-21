#include <iostream>
using namespace std;

long long tinhSoNgay(int d, int m, int y){
    long long cnt = 0;
    y--;
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

void TravelDate(int days, int &d, int &m, int &y){
    d=1, m=1, y=1;
    long long cycles = y/146097;
    y += 400 * cycles;
    days -= cycles * 146097;
    while (days >= 365){
        if (y%400 == 0 || (y%4==0 && y%100 !=0)){
            days -=366;
        }
        else{
            days -= 365;
        }
        y++;
    }
    while ((days >= 29 && m == 2 && (y%400 == 0 || (y%4==0 && y%100 !=0))) || (days >= 28 && m==2) || (days >= 31 && ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))) || (days >= 30)){
        if (m == 2){
            if (y%400 == 0 || (y%4==0 && y%100 !=0)){
                days -= 29;
            }
            else{
                days -= 28;
            }
        }
        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
            days -= 31;
        }
        else{
            days -= 30;
        }
        m++;
    }
    d = days;
}

int main(){
    int d, m, y, n;
    cin >> d >> m >> y >> n;
    long long cnt = tinhSoNgay(d, m, y) - n;
    TravelDate(cnt, d, m, y);
    cout << d << " " << m << " " << y;
    return 0;
}