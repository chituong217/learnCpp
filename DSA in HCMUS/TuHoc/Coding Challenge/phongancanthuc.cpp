#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isSoChinhPhuong(long long n){
    double scp = sqrt(n);
    if (scp - (long long)scp == 0) return true;
    else return false;
}

bool check(long long n, long long mid){
    return isSoChinhPhuong(mid) == true && n % mid == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long a = -1, b = -1;
    long long left = 1, right = 10000000000000;
    while (left <= right){
        long long mid = (left + right)/2;
        if (check(n, mid) == true){
            a = (long long)(sqrt(mid));
            b = (n / mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << a << ' ' << b;

    return 0;
}