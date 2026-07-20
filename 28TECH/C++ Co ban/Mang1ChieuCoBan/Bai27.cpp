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

    int max = -1e9;
    for (int i=0; i<n; i++){
        if (a[i] > max){
            max = a[i];
        }
        mark[a[i]]++;
    }
    for (int i=0; i <= max; i++){
        if (mark[i] > 0){
            cout << i << ' ' << mark[i] << endl;
            mark[i] = 0;
        }
    }

    return 0;
}