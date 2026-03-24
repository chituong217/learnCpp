#include <iostream>

using namespace std;

void sinh(string &s){
    bool isFinal = true;
    for (int i = s.size() - 1; i >= 0; i--){
        if (s[i] == '0'){
            isFinal = false;
            break;
        }
    }

    if (isFinal){
        for (int i = s.size() - 1; i >= 0; i--){
            s[i] = '0';
        }
    }
    else{
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1'){
            s[i] = '0';
            i--;
        }
        s[i] = '1';
    }
}

int main(){
    string s;
    cin >> s;

    sinh(s);

    for (int i = 0; i < (int)s.size(); i++){
        cout << s[i];
    }

    return 0;
}