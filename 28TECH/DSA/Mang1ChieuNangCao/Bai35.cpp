#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int len = 0;
    int max = 0;
    int left = 0;
    for (int right = 0; right < n; right++){
        len++;

        while (abs(a[left] - a[right]) > k){
            left++;
            len--;
        }

        if (len > max){
            max = len;
        }
    }

    cout << max;

    return 0;
}