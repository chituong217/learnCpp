#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string.h>

using namespace std;

bool comp(char a, char b){
    if (a < b){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    string res;
    int len = s.size();
    for (int i = 0; i < len; i++){
        if (s[i] != '0'){
            res += s[i];
        }
        else if (i == len - 1){
            res += s[i];
        }
    }
    cout << res << endl;

    return 0;
}