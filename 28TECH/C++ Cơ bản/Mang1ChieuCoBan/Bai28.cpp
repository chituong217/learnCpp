#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];
int mark[MAX_LEN + 1];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n; i++){
        mark[a[i]]++;
    }

    for (int i=0; i < n; i++){
        if (mark[a[i]] > 0){
            cout << a[i] << ' ' << mark[a[i]] << endl;
            mark[a[i]] = 0;
        }
    }

    return 0;
}