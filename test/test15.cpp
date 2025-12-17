#include <iostream>

using namespace std;


// vi du 1
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

// vi du 2
int findLongestIncreaseByOneSubsequent(int a[], int n){
    if (n == 0) return 0;

    int longestLen = 0;
    int currentLen = 1;

    for (int i = 1; i < n; i++){
        if (a[i] - a[i-1] == 1){
            currentLen++;
        }
        else{
            if (currentLen > longestLen){
                longestLen = currentLen;
            }

            currentLen = 1;
        }
    }

    if (currentLen > longestLen){
        longestLen = currentLen;
    }

    return longestLen;
}


// vidu 3
int findLongestIncreaseArray(int a[], int n){
    if (n == 0) return 0;
    else if (n == 1) return 1;

    int globalDiff = -9999;
    int longestLen = 1;
    int currentLen = 1;

    for (int i = 1; i < n; i++){
        int currentDiff = a[i] - a[i - 1];
        if (currentDiff > 0){
            if (currentDiff == globalDiff){
                currentLen++;
            }
            else{
                if (currentLen > longestLen){
                    longestLen = currentLen;
                }

                globalDiff = currentDiff;
                currentLen = 2;
            }
        }
        else{
            if (currentLen > longestLen){
                longestLen = currentLen;
            }
            currentLen = 1;
            globalDiff = -9999;
        }
    }

    if (currentLen > longestLen){
        longestLen = currentLen;
    }

    return longestLen;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << findLongestIncreaseArray(a, n) << endl;

    return 0;
}