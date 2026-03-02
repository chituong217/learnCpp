#include <iostream>

using namespace std;

int a[200005];
long long F[200005];
long long kq[200005];

int main(){
    int n, k, q;
    cin >> n >> k >> q;


    while (n--){
        int left, right;
        cin >> left >> right;

        a[left] += 1;
        a[right + 1] -= 1;
    }

    
    for (int i = 0; i <= 200000; i++){
        if (i == 0){
            F[i] = a[i];
        }
        else{
            F[i] = 1ll * F[i - 1] + a[i];
        }
    }

    for (int i = 0; i < 200001; i++){
        if (i == 0){
            if (F[i] >= k){
                kq[i]++;
            }
        }
        else{
            if (F[i] >= k){
                kq[i] = kq[i - 1] + 1;
            }
            else{
                kq[i] = kq[i - 1];
            }
        }
    }

    while (q--){
        int left, right;
        cin >> left >> right;

        if (left == 0){
            cout << kq[right] << '\n';
        }
        else{
            cout << kq[right] - kq[left - 1] << '\n';
        }
    }

    return 0;
}