#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] != '0'){
            cout << s[i];
        }
    }

    if (s.size() == 1 && s[0] == '0'){
        cout << '0';
    }

    return 0;
}