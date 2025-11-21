#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return n > 1;
}

bool isDoiXung(vector<int> a, int n){
    int left = 0, right = n - 1;
    while (left <= right){
        if (a[left] != a[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // xu li dong dau tien
    int max = -1e9;
    for (int i = 0; i < n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] == max){
            cout << max << ' ' << i << endl;
            break;
        }
    }

    // xu li dong thu 2
    int min = 1e9;
    for (int i = 0; i < n; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    for (int i = n-1; i >= 0; i--){
        if (a[i] == min){
            cout << min << ' ' << i << endl;
            break;
        }
    }

    // xu li dong thu 3
    int cntPrime = 0;
    for (int i = 0; i < n; i++){
        if (isPrime(a[i]) == true){
            cntPrime++;
        }
    }
    cout << cntPrime << endl;

    // xu li dong thu 4

    // tim submin
    int submin = 1e9;
    bool foundMin = false;
    for (int i = 0; i < n; i++){
        if (a[i] == min && foundMin == false){
            foundMin = true;
        }
        else if (a[i] == min && foundMin == true){
            submin = min;
        }
        else{
            if (a[i] < submin){
                submin = a[i];
            }
        }
    }

    // tim submax
    int submax = -1e9;
    bool foundMax = false;
    for (int i = 0; i < n; i++){
        if (a[i] == max && foundMax == false){
            foundMax = true;
        }
        else if (a[i] == max && foundMax == true){
            submax = max;
        }
        else{
            if (a[i] > submax){
                submax = a[i];
            }
        }
    }
    // tim maxTich
    long long maxTich1 = 1ll*min*submin;
    long long maxTich2 = 1ll*max*submax;
    long long maxTich;
    if (maxTich1 > maxTich2){
        maxTich = maxTich1;
    }
    else{
        maxTich = maxTich2;
    }
    cout << maxTich << endl;

    // xu li dong thu 5
    if (isDoiXung(a, n) == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    // xu li dong thu 6
    long long tich = 1;
    for (int i = 0; i < n; i++){
        tich *= a[i];
        tich %= MOD;
    }
    if (tich < 0){
        tich += MOD;
        tich %= MOD;
    }
    cout << tich << endl;

    return 0;
}