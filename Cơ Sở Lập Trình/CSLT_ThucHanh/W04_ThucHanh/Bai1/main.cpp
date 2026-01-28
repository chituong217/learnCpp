#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long long P01(int n){
    int sum = 0;
    for (int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

double P05(int n){
    double sum = 0;
    for (int i=0; i<=n; i++){
        sum += 1.0/(2*i + 1);
    }
    return sum;
}

long long P09(int n){
    long long tich = 1;
    for (int i=1; i <= n; i++){
        tich *= i;
    }
    return tich;
}

double P13(double x, int n){
    double sum = 0;
    double tmp = 1.0;
    for (int i=1; i<=n; i++){
        tmp *= x*x;
        sum += tmp;
    }
    return sum;
}

double P17(double x, int n){
    double pow = 1, gt = 1, sum = 0;
    for (int i=1; i<=n; i++){
        pow *= x;
        gt *= i;
        sum += pow/gt;
    }
    return sum;
}

long long P21(int n){
    long long sum = 0;
    for (int i=1; i<=n; i++){
        if (n%i==0){
            sum += i;
        }
    }
    return sum;
}

long long P25(int n){
    long long sum = 0;
    for (int i=1; i<=n; i++){
        if (n%i==0 && i%2==0){
            sum += i;
        }
    }
    return sum;
}

int P29(int n){
    int find = -1;
    for (int i=n; i>0; i--){
        if (n%i==0 && i%2==1){
            find = i;
            break;
        }
    }
    return find;
}

double P33(int n){
    double sum = 2;
    for (int i=1; i<=n; i++){
        if (i==1){
            sum = sqrt(sum);
        }
        else{
           sum = sqrt(2 + sum); 
        }
    }
    return sum;
}

double P37(int n){
    if (n >= 1656) {
        cout << fixed << setprecision(2) << 1.00;
        return 0;
    }
    // double sum = pow(2, 1.0/2); 
    double sum = exp(log(2)/2); 
    for (int i=2; i<=n; i++){
        if (i != 2){
            // sum = pow(i + sum, 1.0/i);
            sum = exp( log(i+sum) / i);
        }
    }
    return sum;
}

double P41(int n){
     double sum = 1.0; 
    for (int i = 1; i < n; i++){ 
        sum = 1.0 / (1.0 + sum);
    } 
    sum += 1.0;
    return sum;
}

long long P45(int n){
    long long tich = 1;
    while (n){
        tich *= n;
        n--;
    }
    return tich;
}

long long P49(int n){
    long long first = 0;
    while (n>0){
        first = n%10;
        n/=10;
    }
    return first;
}

long long P53(int n){
    int cnt = 0;
    int max = -1e9;
    while (n){
        if (n%10 > max){
            max = n%10;
            cnt =1;
        }
        else if (n%10 == max){
            cnt++;
        }
        n/=10;
    }
    return cnt;
}

int P57(int n){
    long long tmp = n;
    long long res = 0;
    while(n){
        res = res*10 + n%10;
        n/=10;
    }
    return res == tmp;
}

int P61(int a, int b){
    while (b){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

double P65(int n, double x){
    double sum = x;
    double tmp = x;
    for (int i=1; i <= n; i++){
        tmp = tmp*x*x;
        if (i%2==0){
            sum += tmp;
        }
        else{
            sum -= tmp;
        }
    }
    return sum;
}

double P69(int n, double x){
    double sum = -1;
    double tmp = 1;
    for (int i=1; i <= n; i++){
        tmp = tmp * x * x / ((2.0 * i) * (2.0 * i - 1));
        if (i%2==1){
            sum += tmp;
        }
        else{
            sum -= tmp;
        }
        if (fabs(tmp) < 1e-15) {
            break; 
        }
    }
    return sum;
}

int P73(int d, int m, int y){
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

void P77(int days, int &d, int &m, int &y){
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

void P81(int n){
    while (n){
        cout << n%10 << " ";
        n/=10;
    }
}

int P85(int a, int b){
    while (b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int P89(int a, int b){
    while (a >= b){
        a-=b;
    }
    return a;
}

int main(){
    int choice;
    do{
        cout << "--------------------------------------" << endl;
        cout << "1. P01" << endl;
        cout << "2. P05" << endl;
        cout << "3. P09" << endl;
        cout << "4. P13" << endl;
        cout << "5. P17" << endl;
        cout << "6. P21" << endl;
        cout << "7. P25" << endl;
        cout << "8. P29" << endl;
        cout << "9. P33" << endl;
        cout << "10. P37" << endl;
        cout << "11. P41" << endl;
        cout << "12. P45" << endl;
        cout << "13. P49" << endl;
        cout << "14. P53" << endl;
        cout << "15. P57" << endl;
        cout << "16. P61" << endl;
        cout << "17. P65" << endl;
        cout << "18. P69" << endl;
        cout << "19. P73" << endl;
        cout << "20. P77" << endl;
        cout << "21. P81" << endl;
        cout << "22. P85" << endl;
        cout << "23. P89" << endl;
        cout << "0. Exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> choice;
        if (choice == 1){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P01(n) << endl;
        }
        else if (choice == 2){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << fixed << setprecision(2) << P05(n) << endl;
        }
        else if (choice == 3){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P09(n) << endl;
        }
        else if (choice == 4){
            double x;
            int n;
            cout << "Hay nhap vao x, n: ";
            cin >> x >> n;
            cout << fixed << setprecision(2) <<P13(x, n) << endl;
        }
        else if (choice == 5){
            double x;
            int n;
            cout << "Hay nhap vao x, n: ";
            cin >> x >> n;
            cout << fixed << setprecision(2) <<P17(x, n) << endl;
        }
        else if (choice == 6){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P21(n) << endl;
        }
        else if (choice == 7){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P25(n) << endl;
        }
        else if (choice == 8){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P29(n) << endl;
        }
        else if (choice == 9){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << fixed << setprecision(2) << P33(n) << endl;
        }
        else if (choice == 10){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << fixed << setprecision(2) << P37(n) << endl;
        }
        else if (choice == 11){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << fixed << setprecision(2) << P41(n) << endl;
        }
        else if (choice == 12){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P45(n) << endl;
        }
        else if (choice == 13){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P49(n) << endl;
        }
        else if (choice == 14){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            cout << P53(n) << endl;
        }
        else if (choice == 15){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            if (P57(n) == 1){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if (choice == 16){
            int a, b;
            cout << "Hay nhap vao a, b: ";
            cin >> a >> b;
            cout << (a*b)/P61(a, b) << endl;
        }
        else if (choice == 17){
            double x;
            int n;
            cout << "Hay nhap vao x, n: ";
            cin >> x >> n;
            cout << fixed << setprecision(2) <<P65(x, n) << endl;
        }
        else if (choice == 18){
            double x;
            int n;
            cout << "Hay nhap vao x, n: ";
            cin >> x >> n;
            cout << fixed << setprecision(2) <<P69(x, n) << endl;
        }
        else if (choice == 19){
            int d1, m1, y1, d2, m2, y2;
            cout << "Hay nhap vao d1 m1 y1 d2 m2 y2 : ";
            cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
            cout << P73(d2, m2, y2) - P73(d1, m1, y1) << endl;
        }
        else if (choice == 20){
            int d, m, y, n;
            cout << "Hay nhap vao d, m, y, n :";
            cin >> d >> m >> y >> n;
            long long cnt = P73(d, m, y) - n;
            P77(cnt, d, m, y);
            cout << d << " " << m << " " << y << endl;
        }
        else if (choice == 21){
            int n;
            cout << "Hay nhap vao n: ";
            cin >> n;
            P81(n);
            cout << endl;
        }
        else if (choice == 22){
            int a, b, c;
            cout << "Moi nhap vao a, b, c";
            cin >> a >> b >> c;
            cout << P85(P85(a, b), c) << endl;
        }
        else if (choice == 23){
            int a, b;
            cout << "Moi nhap vao a, b: ";
            cin >> a >> b;
            cout << P89(a, b);
        }
    } while (choice != 0);
    return 0;
}