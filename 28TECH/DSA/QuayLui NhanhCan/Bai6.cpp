#include <iostream>

using namespace std;

// X1, X2, ..., Xn
// X1 = y : Con hau hang 1 dat o cot y

int n, cnt = 0;
int X[100], cot[100], cheo1[100], cheo2[100];

void Try(int i){
    for (int j = 1; j <= n; j++){
        // lua chon cot j de minh dat con hau o hang thu i
        if (cot[j] == 0 && cheo1[i - j + n] == 0 && cheo2[i + j -1] == 0){
            X[i] = j;
            cot[j] = 1;
            cheo1[n + i - j] = 1;
            cheo2[i + j - 1] = 1;

            if (i == n){
                cnt++;
            }
            else{
                Try(i + 1);
            }

            cot[j] = 0;
            cheo1[n + i - j] = 0;
            cheo2[i + j - 1] = 0;
        } 
    }
}

int main(){
    cin >> n;
    Try(1);

    cout << cnt;

    return 0;
}