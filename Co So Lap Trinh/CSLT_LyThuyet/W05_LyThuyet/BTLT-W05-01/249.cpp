#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int check = 1;
    for (int i=1; i<n; i++){
        if (a[i] > a[i-1]){
            check = 0;
        }
    }
    cout << check;
    return 0;
}