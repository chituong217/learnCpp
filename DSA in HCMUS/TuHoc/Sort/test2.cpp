#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// int getDigit(int n, int exp){
//     n /= exp;
//     return n % 10;
// }

// int cntLenNumber(int n){
//     int cnt = 0;
//     while (n){
//         n /= 10;
//         cnt++;
//     }
//     return cnt;
// }

// void radixSort(int a[], int n){
//     int maxLen = 0;
//     for (int i = 0; i < n; i++){
//         maxLen = max(maxLen, cntLenNumber(a[i]));
//     }

//     for (int i = 0; i < maxLen; i++){
//         int exp = pow(10, i);
//         // cac bucket de save cac so
//         vector<int> bucket[10]; // 0 -> 9
//         for (int i = 0; i < n; i++){
//             int digit = getDigit(a[i], exp);
//             bucket[digit].push_back(a[i]);
//         }

//         int index = 0;
//         for (int i = 0; i < 10; i++){
//             for (int j = 0; j < (int)bucket[i].size(); j++){
//                 a[index] = bucket[i][j];
//                 index++;
//             }
//         }

//         // luc nay da gan xong lai cac bucket vao a
//         // tiep tuc vong lap cho exponential tiep theo
//     }
// }


void radixSort(int a[], int n){
    int maxVal = a[0];
    for (int i = 0; i < n; i++){
        maxVal = max(maxVal, a[i]);
    }

    vector<int> bucket[10]; // cac bucket luu gia tri

    // tinh expential cua maxVal
    for (int exp = 1; (maxVal / exp) > 0; exp *= 10){
        for (int i = 0; i < n; i++){
            int digit = (a[i] / exp) % 10; // digit cua a[i]
            bucket[digit].push_back(a[i]); // them a[i] vao bucket tuong ung
        }

        int index = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < (int)bucket[i].size(); j++){
                a[index] = bucket[i][j];
                index++;
            }
            bucket[i].clear();
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

