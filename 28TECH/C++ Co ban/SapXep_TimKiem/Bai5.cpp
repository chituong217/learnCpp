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

    int valBest = a[0];
    int cntBest = 1;
    int cntTmp = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            cntTmp++;
        } else {
            if (cntTmp > cntBest) {
                cntBest = cntTmp;
                valBest = a[i-1];
            }
            cntTmp = 1;
        }
    }
    if (cntTmp > cntBest) {
        cntBest = cntTmp;
        valBest = a[n-1];
    }
    cout << valBest << ' ' << cntBest;
    return 0;
}