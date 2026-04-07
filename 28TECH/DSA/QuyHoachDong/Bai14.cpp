#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll F[1000005];

int main(){ 
    int n;
    cin >> n;

    // khoi tao truong hop nho nhat
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i >= j){
                F[i] += F[i - j];
                F[i] %= mod;
            }
        }
    }

    cout << F[n];

    return 0;
}