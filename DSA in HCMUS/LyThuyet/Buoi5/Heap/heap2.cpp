#include <iostream>

using namespace std;

bool checkMaxHeap(int a[], int n){
    for (int i = 0; i <= (n - 1)/2; i++){
        int p1 = 2 * i + 1, p2 = 2 * i + 2;
        if (p1 <= n - 1){
            if (a[i] < a[p1]){
                return false;
            }
        }
        if (p2 <= n - 1){
            if (a[i] < a[p2]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool check = checkMaxHeap(a, n);
    if (check == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}