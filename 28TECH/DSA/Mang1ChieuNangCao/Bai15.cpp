#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    long long minDistance = LONG_LONG_MAX;
    long long cnt = 0;

    for (int i = 1; i < n; i++){
        long long tmpDistance = a[i] - a[i - 1];

        if (tmpDistance == minDistance){
            cnt++;
        }
        if (tmpDistance < minDistance){
            minDistance = tmpDistance;
            cnt = 1;
        }
    }

    cout << minDistance << ' ' << cnt;
    
    return 0;
}