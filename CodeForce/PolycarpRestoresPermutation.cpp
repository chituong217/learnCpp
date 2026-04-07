#include <iostream>
#define ll long long

using namespace std;

int main(){
    int n;
    cin >> n;

    int q[n - 1];
    ll prefixSum[n], minVal = 0;
    prefixSum[0] = 0;
    for (int i = 0; i < n - 1; i++){
        cin >> q[i];
        prefixSum[i + 1] = prefixSum[i] + q[i];
    }

    for (int i = 0; i < n; i++){
        if (prefixSum[i] < minVal){
            minVal = prefixSum[i];
        }
    }

    ll p[n];
    p[0] = 1 - minVal;
    bool ok = true;
    for (int i = 1; i < n; i++){
        p[i] = p[0] + prefixSum[i];
    }

    int visited[n + 1] = {0};
    for (int i = 0; i < n; i++){
        if (p[i] < 1 || p[i] > n || visited[p[i]] == 1){
            ok = false;
            break;
        }
        visited[p[i]] = 1;
    }

    if (ok){
        for (int i = 0; i < n; i++){
            cout << p[i] << ' ';
        }
    }
    else{
        cout << "-1";
    }

    return 0;
}