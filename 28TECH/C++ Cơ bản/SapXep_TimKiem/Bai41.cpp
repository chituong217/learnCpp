#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < n; right++){
        sum += a[right];
        while (sum > x && left <= right){
            sum -= a[left];
            left++;
        }
        if (sum == x){
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}