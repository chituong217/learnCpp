#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    string res;

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] != '2' && s[i] != '8' && s[i] != 't' && s[i] != 'e' && s[i] != 'c' && s[i] != 'h'){
            res += s[i];
        }
    }

    if (res.size() > 0){
        cout << res;
    }
    else{
        cout << "EMPTY";
    }

    return 0;
}