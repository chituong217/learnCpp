#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 1e9;
    for (int i = 0; i < n-1; i++){
        int dis = abs(a[i] - a[i+1]);
        if (dis < res){
            res = dis;
        }
    }
    cout << res;
    return 0;
}