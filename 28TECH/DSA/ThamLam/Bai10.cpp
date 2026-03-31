#include <iostream>
#include <algorithm>
#include <queue>

#define mod 1000000007

using namespace std;

int main(){
    int n;
    cin >> n;
    
    priority_queue<long long> Q;
    for (int i = 0; i < n; i++){
        long long tmp; cin >> tmp;
        Q.push(tmp);
    }

    long long sum = 0;
    while (Q.size() > 1){
        long long day1 = Q.top();
        Q.pop();
        long long day2 = Q.top();
        Q.pop();

        long long newDay = day1 + day2;
        sum = ((sum % mod) + (newDay % mod)) % mod;

        Q.push(newDay);
    }

    cout << sum;
    
    return 0;
}