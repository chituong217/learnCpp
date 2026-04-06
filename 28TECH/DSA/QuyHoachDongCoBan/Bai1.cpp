#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll gt[1000005];

void ktao(){
    gt[0] = 1;
    for (int i = 1; i <= 1000000; i++){
        gt[i] = ((gt[i - 1] % mod) * (i % mod)) % mod;
    }
}

int main(){
    ktao();
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        cout << gt[n] << '\n';
    }

    return 0;
}