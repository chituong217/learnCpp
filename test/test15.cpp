#include <iostream>

using namespace std;

int findLES(int a[], int n){
    if (n == 0) return 0;

    int currentLen = 1;
    int maxLen = 0;

    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1]){
            currentLen++;
        }
        else{
            if (currentLen > maxLen){
                maxLen = currentLen;
            }

            currentLen = 1;
        }
    }

    if (currentLen > maxLen){
        maxLen = currentLen;
    }

    return maxLen;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << findLES(a, n) << endl;

    return 0;
}