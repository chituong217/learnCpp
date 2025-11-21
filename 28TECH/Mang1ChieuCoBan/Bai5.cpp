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
    int cnt = 0;
    for (int i=0; i<n; i ++){
        if (a[i] % 2 == 0 && i % 2 == 0){
            cout << a[i] << ' ';
            cnt++;
        }
    }
    if (cnt == 0){
        cout << "NONE" << endl;
    }
    return 0;
}