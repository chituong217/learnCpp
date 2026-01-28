#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000
using namespace std;

bool isPrime(int n){
    for (int i=2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return n > 1;
}

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    double sum = 0.0;
    for (int i=0; i<n; i++){
        if (isPrime(a[i])){
            sum += a[i];
            cnt++;
        }
    }
    sum /= cnt;
    cout << fixed << setprecision(3) << sum << endl;
    return 0;
}