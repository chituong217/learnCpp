#include <iostream>
#include <string>
#define ll long long

using namespace std;

ll dp[20];

int main(){
    string s;
    cin >> s;

    ll sum = 0;
    int n = s.size();

    dp[0] = (ll)(s[0] - '0');
    sum += dp[0];
    for (int i = 1; i < n; i++){
        dp[i] = dp[i - 1] * 10 + (ll)(s[i] - '0') * (i + 1);
        sum += dp[i];
    }

    cout << sum;

    return 0;
}