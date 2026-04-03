#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> v;

    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '1'){
            cnt++;
        }
        else{
            v.push_back(cnt);
            cnt = 0;
        }
    }

    if (cnt != 0){
        v.push_back(cnt);
    }

    sort(v.begin(), v.end(), greater<int>());
    int ti = 0, teo = 0;
    for (int i = 0; i < (int)v.size(); i++){
        if (i % 2 == 0){
            ti += v[i];
        }
        else{
            teo += v[i];
        }
    }

    cout << ti;

    return 0;
}