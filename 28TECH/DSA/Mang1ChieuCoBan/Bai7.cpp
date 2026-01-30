#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int minDiff = INT_MAX;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (abs(a[i] - a[j]) < minDiff){
                minDiff = abs(a[i] - a[j]);
            }
        }
    }

    cout << minDiff;

    return 0;
}