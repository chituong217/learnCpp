#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int getDigit(int num, int k){
    num /= (int)pow(10, k);
    return num % 10;
}

void radixSort(int a[], int n){
    int maxVal = a[0];
    for (int i = 1; i < n; i++){
        maxVal = max(maxVal, a[i]);
    }

    int maxDigit = 0;
    while(maxVal){
        maxVal /= 10;
        maxDigit++;
    }

    for (int i = 0; i < maxDigit; i++){
        vector<int> Bin[10];
        
        for (int j = 0; j < n; j++){
            int digit = getDigit(a[j], i);
            Bin[digit].push_back(a[j]);
        }

        int idx = 0;
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < (int)Bin[j].size(); k++){
                a[idx] = Bin[j][k];
                idx++;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    radixSort(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}