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

    int maxFre = 0;
    for (int i=0; i < n; i++){
        if (mark[a[i]] > 0 && mark[a[i]] > maxFre){
            maxFre = mark[a[i]];
        }
    }

    for (int i=0; i<n; i++){
        if (mark[a[i]] == maxFre){
            cout << a[i] << ' ' << maxFre;
            return 0;
        }
    }

    return 0;
}