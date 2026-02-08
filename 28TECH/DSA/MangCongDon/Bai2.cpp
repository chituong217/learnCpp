#include <iostream>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long prefix_sum[n];
    for (int i = 0; i < n; i++){
        if (i == 0){
            prefix_sum[i] = a[i];
        }
        else{
            prefix_sum[i] = prefix_sum[i - 1] + (long long)a[i];
        }
    }

    while (q--){
        int left, right;
        cin >> left >> right;
        if (left == 0){
            cout << prefix_sum[right] << endl;
        }
        else{
            cout << prefix_sum[right] - prefix_sum[left - 1] << endl;
        }
    }

    return 0;
}