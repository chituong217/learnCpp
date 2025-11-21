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
    for (int i=0; i < n-1; i++){
        for (int j = i+1; j<n; j++){
            if (abs(a[i] - a[j]) < min){
                min = abs(a[i] - a[j]);
            }
        }
    }

    cout << min;

    return 0;
}