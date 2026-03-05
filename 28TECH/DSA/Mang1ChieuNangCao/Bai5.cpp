#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        int mini = 1e9, maxi = -1e9;

        if (i == 0){
            mini = a[i + 1] - a[i];
            maxi = a[n - 1] - a[i];
        }
        else if (i == n - 1){
            mini = a[i] - a[i - 1];
            maxi = a[i] - a[0];
        }
        else{
            mini = min(a[i] - a[i - 1], a[i + 1] - a[i]);
            maxi = max(a[i] - a[0], a[n - 1] - a[i]);
        }

        cout << mini << ' ' << maxi << '\n';
    }
    
    return 0;
}