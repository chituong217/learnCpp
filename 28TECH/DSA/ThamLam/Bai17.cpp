#include <iostream>
#include <cmath>

using namespace std;

void bubbleSort(long long a[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bubbleSort(a, n);
    

    long long p1 = 1, p2 = 1, p3 = 1, p4 = 1;
    if (n == 1){
        cout << a[0];
        return 0;
    }
    else if (n == 2){
        p1 = a[0] * a[1];
        p2 = a[n - 1] * a[n - 2];
        cout << max(p1, p2);
        return 0;
    }
    else{
        p1 = a[0] * a[1];
        p2 = a[n - 1] * a[n - 2];
        p3 = a[n - 1] * a[n - 2] * a[n - 3];
        p4 = a[0] * a[1] * a[n - 1];
        
        p1 = max(p1, p2);
        p3 = max(p3, p4);
        p1 = max(p1, p3);
        cout << p1;
    }

    return 0;
}