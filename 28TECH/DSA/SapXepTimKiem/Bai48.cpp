#include <iostream>

using namespace std;

bool check (int length, int width, int n, long long canh){
    long long maxCapacity = (canh / length) * (canh / width);
    return n <= maxCapacity;
}

int main(){
    int a, b, n;
    cin >> a >> b >> n;

    long long left = 1, right = 1ll * max(a,b) * n;
    long long ans = -1;
    while (left <= right){
        long long mid = (left + right)/2;
        
        if (check(b, a, n, mid) == true){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}