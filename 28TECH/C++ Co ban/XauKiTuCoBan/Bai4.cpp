#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isSoDep(string s){
    int len = s.size();
    for (int i = 0; i < len - 1; i++){
        if (abs(s[i] - s[i+1]) != 1){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    if (isSoDep(s)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}