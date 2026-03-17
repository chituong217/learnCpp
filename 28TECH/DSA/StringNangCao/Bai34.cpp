#include <iostream>
#include <string>

using namespace std;

bool isSoDep(string s){
    bool isTang = false, isGiam = false;

    for (int i = 1; i < (int)s.size(); i++){
        if (s[i] > s[i - 1]){
            isTang = true;
        }
        if (s[i] < s[i - 1]){
            isGiam = true;
        }
    }

    if (isTang == true && isGiam == true){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    string s;
    cin >> s;

    if (isSoDep(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}