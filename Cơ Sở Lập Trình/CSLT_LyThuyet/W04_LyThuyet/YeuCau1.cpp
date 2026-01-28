#include <iostream>
using namespace std;

struct date{
    int d;
    int m; 
    int y;
};

void nhap(date *Date){
    cin >> Date -> d;
    cin >> Date -> m;
    cin >> Date -> y;
}

void xuat(date Date){
    cout << "Ngay " << Date.d;
    cout << " Thang " << Date.m;
    cout << " Nam " << Date.y << endl;
}

int compareDay(date d1, date d2){
    // So sanh nam
    if (d1.y > d2.y){
        return 1;
    }
    else if (d1.y < d2.y){
        return 0;
    }
    else{
        // So sanh thang
        if (d1.m > d2.m){
            return 1;
        }
        else if (d1.m < d2.m){
            return 0;
        }
        else{
            // So sanh ngay
            if (d1.d > d2.d){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

int songaycuathang(date Day){
    if (Day.m == 2){
        if (Day.y%400 == 0 || (Day.y%4==0 && Day.y%100!=0)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else if (Day.m == 1 || Day.m == 3 || Day.m == 5 || Day.m == 7 || Day.m == 8 || 10 || Day.m == 12){
        return 31;
    }
    else{
        return 30;
    }
}

void tomorrow(date *Day){
    int ngaycuathang = songaycuathang(*Day);
    if (Day -> d == ngaycuathang){
        if (Day -> m == 12){
            (Day->y)++;
            (Day->m)=1;
            (Day->d)=1;
        }
        else{
            (Day->m)++;
            (Day->d)=1;
        }
    }
    else{
        (Day->d)++;
    }
}

void yesterday(date *Day){
    if (Day->d == 1){
        if (Day->m == 1){
            (Day->y)--;
            (Day->m) = 12;
            (Day->d) = 31;
        }
        else{
            (Day->m)--;
            int ngaycuathang = songaycuathang(*Day);
            (Day->d) = ngaycuathang;
        }
    }
    else{
        (Day->d)--;
    }
}

int main(){
    date d1, d2;
    nhap(&d1);
    nhap(&d2);
    if (compareDay(d1, d2) == 1){
        cout << "Day 1 is later than Day 2\n";
    }
    else{
        cout << "Day 1 is not later than Day 2\n";
    }
    tomorrow(&d1);
    xuat(d1);
    yesterday(&d2);
    xuat(d2);
    return 0;
}