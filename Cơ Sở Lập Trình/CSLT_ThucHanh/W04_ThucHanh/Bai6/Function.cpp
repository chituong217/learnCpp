#include "Function.h"

void nhap(istream &in, SNgay &date){
    in >> date.d;
    in >> date.m;
    in >> date.y;
}

void xuat(ostream &out, SNgay date){
    out << "Date : day " << date.d << " month " << date.m << " year " << date.y << endl;
}

bool checkNamnhuan(SNgay date){
    if ((date.y%400 == 0) || (date.y%4 == 0 && date.y%100 != 0)){
        return true;
    }
    else{
        return false;
    }
}

int tinhSTTngaytrongnam(SNgay date){
    int daysinMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (checkNamnhuan(date)){
        daysinMonth[2] = 29;
    }
    int stt = date.d;
    for (int i = 1; i < date.m; i++){
        stt += daysinMonth[i];
    }
    return stt;
}

long long tinhSTTngay(SNgay date){
    long long stt = (1ll * (date.y-1)/400) * (97*366 + 303*365);
    int soNam = (date.y-1)%400;
    for (int i=1; i <= soNam; i++){
        if (i%4 == 0 && i%100 != 0){
            stt += 366;
        }
        else{
            stt += 365;
        }
    }
    stt += tinhSTTngaytrongnam(date);
    return stt;
}

SNgay timNgaytuSTT(long long stt){
    SNgay result = {1, 1, 1};
    // tru di cac chu ki 400 nam
    long long remaining_days = stt - 1;
    long long cycles = remaining_days / (97*366 + 303*365);
    result.y += cycles * 400;
    remaining_days %= (97*366 + 303*365);
    
    // tru di so nam du
    int years = 0;
    while (remaining_days > 0){
        long long currentyear = years + result.y;
        int daysinyear = 0;
        if ((currentyear%4 == 0 && currentyear%100 != 0) || currentyear%400 == 0){
            daysinyear = 366;
        }
        else{
            daysinyear = 365;
        }

        // kiem tra so ngay con lai
        if (remaining_days >= daysinyear){
            remaining_days -= daysinyear;
            years++;
        }
        else{
            break;
        }
    }
    result.y += years;

    // Tru di so thang con lai
    int daysinmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (result.y%400 == 0 || (result.y%4 == 0 && result.y%100 !=0)){
        daysinmonth[2] = 29;
    }
    for (int i=1; i <= 12; i++){
        if (remaining_days >= daysinmonth[i]){
            remaining_days -= daysinmonth[i];
            result.m++;
        }
        else{
            break;
        }
    }
    // so ngay con lai
    result.d = remaining_days + 1;
    return result;
}

SNgay tinhNgaytruocdokngay(SNgay date, int k){
    long long stt = tinhSTTngay(date);
    stt -= k;
    return timNgaytuSTT(stt);
}

SNgay tinhNgaysaudokngay(SNgay date, int k){
    long long stt = tinhSTTngay(date);
    stt += k;
    return timNgaytuSTT(stt);
}

long long tinhKhoangcachhaingay(SNgay date1, SNgay date2){
    long long distance = abs(tinhSTTngay(date2) - tinhSTTngay(date1));
    return distance;
}

int sosanhHaingay(SNgay date1, SNgay date2){
    long long ss = tinhSTTngay(date1) - tinhSTTngay(date2);
    if (ss > 0){
        return 1;
    }
    else if (ss < 0){
        return -1;
    }
    else{
        return 0;
    }
}