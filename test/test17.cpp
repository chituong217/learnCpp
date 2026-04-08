#include <bits/stdc++.h>

using namespace std;

int getDigit(int num, int k){
    int mod = pow(10, k);
    num /= mod;
    return num % 10;
}

void radixSort(int a[], int n){
    int maxVal = a[0];
    for (int i = 0; i < n; i++){
        maxVal = max(a[i], maxVal);
    }

    int maxDigit = 0;
    while (maxVal){
        maxVal /= 10;
        maxDigit++;
    }

    for (int i = 0; i < maxDigit; i++){
        vector<int> B[10];

        for (int j = 0; j < n; j++){
            int digit = getDigit(a[j], i);
            B[digit].push_back(a[j]);
        }

        int idx = 0;
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < (int)B[j].size(); k++){
                a[idx] = B[j][k];
                idx++;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    radixSort(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}