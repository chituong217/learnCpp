#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long prefixSum[n];
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    int q;
    cin >> q;
    while(q--){
        int left, right;
        cin >> left >> right;
        left--;
        right--;

        if (left == 0){
            cout << prefixSum[right] << '\n';
        }
        else{
            cout << prefixSum[right] - prefixSum[left - 1] << '\n';
        }
    }


    return 0;
}