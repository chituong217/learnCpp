#include <iostream>
#define ll long long 
#define mod 1000000007

using namespace std;

ll F[100005];

void solve(int k){
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i <= k; i++){
        for (int j = 0; j < i; j++){
            F[i] += F[j];
            F[i] %= mod;
        }
    }

    for (int i = k + 1; i <= 100000; i++){
        for (int j = 1; j <= k; j++){
            F[i] += F[i - j];
            F[i] %= mod;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    solve(k);
    cout << F[n];

    return 0;
}