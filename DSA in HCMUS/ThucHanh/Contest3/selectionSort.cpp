#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // selectionSort
    for (int i = 0; i < n; i++){
        int minPos = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[minPos]){
                minPos = j;
            }
        }

        if (a[i] > a[minPos]){
            cout << i << ' ' << minPos << '\n';
            swap(a[i], a[minPos]);
        }
    }

    return 0;
}