#include <iostream>
#define MAX_LEN 100

using namespace std;

void merge(int a[], int b[], int n, int m){
    int i = 0, j = 0;
    while (i < n && j < m){
        if (a[i] <= b[j]){
            cout << a[i] << " ";
            i++;
        }
        else{
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < n){
        cout << a[i] << " ";
        i++;
    }
    while (j < m){
        cout << b[j] << " ";
        j++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[MAX_LEN], b[MAX_LEN];
    for (int i= 0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    merge(a, b, n, m);
    return 0;
}