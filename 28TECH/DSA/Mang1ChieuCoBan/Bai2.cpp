#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isPrime(int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return n > 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    int cnt = 0;
    double average = 0;

    for (int i = 0; i < n; i++){
        if (isPrime(v[i]) == true){
            cnt++;
            average += v[i];
        }
    }

    average /= (double)cnt;
    cout << fixed << setprecision(3) << average;

    return 0;
}