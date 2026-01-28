#include <iostream>
using namespace std;

#define MAX_LEN 100

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int min = 1e9, max = -1e9;
    for (int i=0; i<n; i++){
        if (a[i]%2 == 0 && a[i] > max){
            max = a[i];
        }
        else if (a[i] % 2 == 1 && a[i] < min){
            min = a[i];
        }
    }
    cout << max << " " << min; 
    return 0;
}