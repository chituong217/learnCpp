#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ok, s, visited[100];
int a[100];

void Try(int cnt, int sum){
    if (ok){
        return;
    }
    
    if (cnt == k){
        ok = 1;
        return;
    }

    for (int j = 1; j <= n; j++){
        if (visited[j] == 0){
            visited[j] = 1;

            if (sum == s){
                Try(cnt + 1, 0);
            }
            else if (sum < s){
                Try(cnt, sum + a[j]);
            }

            visited[j] = 0;
        }
    }
}

int main(){
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }

    if (s % k != 0){
        cout << "0";
    }
    else{
        s /= k;
        Try(1, 0);

        cout << ok;
    }

    return 0;
}