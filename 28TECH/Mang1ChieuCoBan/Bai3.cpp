#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int min = 1e9;
    for (int i=0; i<n; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (a[i] == min){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}