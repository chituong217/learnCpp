#include <iostream>

using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;

    int a[200001];
    for (int i = 0; i < 200001; i++){
        a[i] = 0;
    }

    while (n--){
        int left, right;
        cin >> left >> right;

        a[left] += 1;
        a[right + 1] -= 1;
    }

    int F[200001];
    for (int i = 0; i <= 200000; i++){
        if (i == 0){
            F[i] = a[i];
        }
        else{
            F[i] = F[i - 1] + a[i];
        }
    }

    int kq[200001];
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
            cout << a[right] << endl;
        }
        else{
            cout << a[right] - a[left - 1] << endl;
        }
    }

    return 0;
}