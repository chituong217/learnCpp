#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    string res;
    int len = s.size();
    for (int i = 0; i < len; i++){
        if (!(s[i] == '2' || s[i] == '8' || s[i] == 't' || s[i] == 'e' || s[i] == 'c' || s[i] == 'h')){
            res.push_back(s[i]);
        }
    }
    if (res.size() == 0){
        cout << "EMPTY" << endl;
    }
    else{
        cout << res << endl;
    }
    return 0;
}