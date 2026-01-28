#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    string res = "";
    for (int i = 0; i < k; i++){
        res += s[i];
    }
    res += "28tech";
    for (int i = k; i < (int)s.size(); i++){
        res += s[i];
    }
    cout << res << endl;
    return 0;
}