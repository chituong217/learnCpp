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

    int mark[MAX_LEN];
    int idx = 0;

    for (int i=0; i<n; i++){
        int check = 1;
        for (int j=0; j<idx; j++){
            if (a[i] == mark[j]){
                check = 0;
                break;
            }
        }
        if (check == 1){
            cout << a[i] << ' ';
            mark[idx] = a[i];
            idx++;
        }
    }
    
    return 0;
}