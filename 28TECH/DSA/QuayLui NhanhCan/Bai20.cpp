#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string s;
string res;

void Try(int pos){
    if ((int)res.size() == k){
        for (int j = 0; j < k; j++){
            cout << res[j];
        }
        cout << '\n';
        return;
    }

    for (int j = pos; j < n; j++){
        res += s[j];

        Try(j);

        res.pop_back();
    }
}

int main(){
    cin >> n >> k >> s;
    
    sort(s.begin(), s.end());

    Try(0);

    return 0;
}