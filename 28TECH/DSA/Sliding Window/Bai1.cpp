#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long sum = 0, max = 0;
    int left = 0, right = 0, maxLeft = 0, maxRight = 0;

    while (right < n){
        sum += a[right];

        if (right - left + 1 == k){
            if (sum > max){
                max = sum;
                maxLeft = left;
                maxRight = right;
            }

            sum -= a[left];
            left++;
        }

        right++;
    }

    cout << max << endl;
    for (int i = maxLeft; i <= maxRight; i++){
        cout << a[i] << ' ';
    }

    return 0;
}