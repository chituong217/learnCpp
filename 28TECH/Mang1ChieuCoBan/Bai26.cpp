#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];
int mark[MAX_LEN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n; i++){
        mark[a[i]] = 1;
    }
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (mark[a[i]] == 1){
            cnt++;
            mark[a[i]] = 0;
        }
    }
    cout << cnt;

    return 0;
}