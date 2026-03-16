#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    cin >> s;

    long long cnt = 0;
    map<char,long long> mp;
    for (int i = 0; i < (int)s.size(); i++){
        mp[s[i]]++;
        
        cnt += mp[s[i]];
    }

    cout << cnt;

    return 0;
}