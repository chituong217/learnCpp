#include <iostream>
#include <algorithm>

using namespace std;

int F[1000005];

void solve(int a[], int n, int s){
    F[0] = 0;

    for (int i = 1; i <= s; i++){
        F[i] = 1e9;
        for (int j = 0; j < n; j++){
            if (i - a[j] >= 0){
                F[i] = min(F[i], F[i - a[j]] + 1);
            }
        }
    }
}

int main(){
    int n, s;
    cin >> n >> s;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    solve(a, n, s);
    if (F[s] == 1e9){
        cout << "-1\n";
    }
    else{
        cout << F[s];
    }

    return 0;
}