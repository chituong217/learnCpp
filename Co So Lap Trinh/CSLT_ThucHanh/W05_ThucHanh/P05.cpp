#include <iostream>
#define MAX_LEN 100

using namespace std;

void selectionSort(int a[], int n){
    for (int i=0; i<n; i++){
        if (a[i] % 2 == 0){
            int min_pos = i;
            for (int j= i+1; j < n; j++){
                if (a[j] < a[min_pos] && a[j]%2==0){
                    min_pos = j;
                }
            }
            int tmp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = tmp;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    selectionSort(a, n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}