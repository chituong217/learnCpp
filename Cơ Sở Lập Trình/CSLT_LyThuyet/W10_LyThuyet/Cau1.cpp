// Tôi cam kết bài làm này là do tôi tự làm, ko phải nhờ người khác làm giùm, ko phải nhờ AI làm giùm

#include <iostream>

using namespace std;

// cau a
int check(int a[], int n){
    int find = -1;
    for (int i = 0; i < n; i++){
        if (a[i] == -1){
            find = i;
            break;
        }
    }

    if (find == 0){
        int d = a[2] - a[1];
        if (a[1] - d >= 0){
            a[0] = a[1] - d;
        }
    }
    else{
        int d = 0;
        if (find == n-1){
            d = a[1] - a[0];
            a[n-1] = a[n-2] + d;
        }
        else{
            d = a[find + 1] - a[find - 1];
            d /= 2;
            a[find] = a[find - 1] + d;
        }
    }

    if (a[find] == -1) return 0;
    else return 1;
}

// cau b
void findLIS(int a[], int n, int &start, int &end){
    start = end = -1;

    if (n < 3) return;

    int maxLen = 1;
    int currentLen = 0;
    int diff = a[1] - a[0];

    if (diff > 0){
        currentLen = 2;
    }
    else{
        currentLen = 1;
    }
    maxLen = currentLen;

    for (int i = 2; i < n; i++){
        int currentDiff = a[i] - a[i - 1];
        if (diff > 0 && currentDiff == diff){
            currentLen++;
        }
        else{
            diff = currentDiff;

            if (currentDiff > 0){
                currentLen = 2;
            }
            else{
                currentLen = 1;
            }

        }

        if (currentLen >= 3 && currentLen >= maxLen){
            end = i;
            maxLen = currentLen;
        }
    }

    if (end != -1){
        start = end - maxLen + 1;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

   
    return 0;
}