#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
using namespace std;


int a[MAX_LEN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int min = 1e9, max = -1e9;
    for (int i=0; i<n; i++){
        if (a[i] > max){
            max = a[i];
        }
        if (a[i] < min){
            min = a[i];
        }
    }
    for (int i = n-1; i >= 0; i--){
        if (a[i] == min){
            cout << i << ' ';
            break;
        }
    }
    for (int i=0; i<n; i++){
        if (a[i] == max){
            cout << i << ' ';
            break;
        }
    }
    return 0;
}