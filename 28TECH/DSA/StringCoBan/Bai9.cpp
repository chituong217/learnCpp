#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    int k;

    cin >> s;
    cin >> k;

    string res;
    res += s.substr(0, k);
    res += "28tech";
    res += s.substr(k);

    cout << res;

    return 0;
}