#include <iostream>
#define MAX_LEN 100

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i < n; i++){
        cin >> a[i];
    }
    int max = -1e9;
    for (int i=0; i < n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    int max2 = -1e9;
    for (int i=0; i < n; i++){
        if (a[i] != max && a[i] >max2){
            max2 = a[i];
        }
    }
    cout << max2;
    return 0;
}