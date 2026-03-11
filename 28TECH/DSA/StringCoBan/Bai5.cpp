#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt = 0;
    string res;
    for (int i = s.size() - 1; i >= 0; i--){
        res += s[i];
        cnt++;

        if (cnt % 3 == 0 && i != 0){
            res += ',';
        }
    }
    reverse(res.begin(), res.end());

    cout << res;

    return 0;
}