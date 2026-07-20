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

    int mark[MAX_LEN + 1];
    for (int i=0; i <= MAX_LEN; i++){
        mark[i] = 0;
    }
    
    
    for (int i=0; i<n; i++){
        mark[a[i]]++;
    }

    for (int i=0; i<n; i++){
        if (mark[a[i]] > 0){
            cout << a[i] << ' ' << mark[a[i]] << endl;
            mark[a[i]] = 0;
        }
    }
    return 0;
}