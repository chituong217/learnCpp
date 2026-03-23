#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &v, int x, long long h){
    long long tong = 0;
    for (int i = 0; i < (int)v.size(); i++){
        if (h > v[i]){
            tong += h - v[i];
        }
        if (tong > x){
            return false;
        }
    }

    return tong <= x;
}

long long findHighestTank(vector<int> &v, int x){
    long long left = 1, right = 9e18;

    long long ans = -1;
    while (left <= right){
        long long mid = (left + right)/2;
        if (check(v, x, mid) == true){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        cout << findHighestTank(v, x) << '\n';
    }

    return 0;
}