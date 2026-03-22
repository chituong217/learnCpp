#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    long long left = 1, right = 1e18;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] < right){
            right = v[i];
        }
    }

    long long res = -1;
    right *= 1ll * t;

    while (left <= right){
        long long mid = (left + right)/2;

        long long products = 0;
        for (int i = 0; i < (int)v.size(); i++){
            products += mid/v[i];
        }

        if (products >= t){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << res;

    return 0;
}