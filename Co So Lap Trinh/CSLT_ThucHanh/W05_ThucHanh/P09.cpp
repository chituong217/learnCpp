#include <iostream>
#define MAX_LEN 100

using namespace std;

bool binarySearch(int a[], int l, int r, int x){
    while (l <= r){
        int m = (l+r)/2;
        if (a[m] == x){
            return true;
        }
        else if (a[m] < x){
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n; 
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (binarySearch(a, 0, i-1, a[i]) == 0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}