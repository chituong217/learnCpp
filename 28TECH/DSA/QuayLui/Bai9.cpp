#include <iostream>
#include <algorithm>

using namespace std;

long long n, s;
int a[100];
int ok = 0;
int minNum = INT_MAX;

void Try(int i, long long sum, int cnt){
    if (cnt >= minNum){
        return;
    }

    if (sum == s){
        ok = 1;
        minNum = cnt;
        return;
    }

    if (i > n || sum > s){
        return;
    }

    Try(i + 1, sum + a[i], cnt + 1);
    Try(i + 1, sum, cnt);
}

int main(){
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n, greater<int>());
    Try(1, 0, 0);

    if (ok == 0){
        cout << "-1";
    }
    else{
        cout << minNum;
    }

    return 0;
}