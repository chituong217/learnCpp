#include <iostream>
#define ll long long 
#define mod 1000000007

using namespace std;

ll F[1000005];

void ktao(){
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= 1000000; i++){
        F[i] = ((F[i - 1] % mod) + (F[i - 2] % mod)) % mod;
    }
}

int main(){
    ktao();
    int t;
    cin >> t;
    
    while (t--){
        int n; cin >> n;

        cout << F[n] << "\n";
    }

    return 0;
}