#include <iostream>

using namespace std;

int n, k, s;
int cnt = 0;
int sum = 0;
int X[100];
// bool visited[100] = {false};

void Try(int i){
    for (int j = X[i - 1] + 1; j <= n; j++){
        X[i] = j;
        sum += j;

        if (i == k){
            if (sum == s){
                cnt++;
            }
        }
        else{
            Try(i + 1);
        }

        sum -= j;
    }

}

int main(){
    cin >> n >> k >> s;

    Try(1);
    cout << cnt;

    return 0;
}