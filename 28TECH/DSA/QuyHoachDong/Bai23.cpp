#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    s = "0" + s;

    int n = s.size();
    bool F[n + 5][n + 5];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            F[i][j] = false;
        }
    }

    for (int len = 1; len <= n; len++){
        // len la do dai xau con
        for (int left = 1; left <= n - len + 1; left++){
            // left la can trai cua xau co, chay tu 1 den n - len + 1
            int right = left + len - 1;
            // right la can phai cua xau con

            if (len == 1){
                // truong hop nho nhat
                F[left][right] = true;
            }
            else if (len == 2){
                // left + 1 > right - 1
                if (s[left] == s[right]){
                    F[left][right] = true;
                }
                else{
                    F[left][right] = false;
                }
            }
            else{
                if (s[left] == s[right] && F[left + 1][right - 1] == true){
                    F[left][right] = true;
                }
                else{
                    F[left][right] = false;
                }
            }
        }
    }

    int maxLen = 0;
    for (int len = 1; len <= n; len++){
        for (int left = 1; left <= n - len + 1; left++){
            int right = left + len - 1;

            if (F[left][right] == true){
                maxLen = right - left + 1;
            }
        }
    }

    cout << maxLen;

    return 0;
}