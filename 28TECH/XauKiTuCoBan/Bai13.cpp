#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?'){
            s[i] = ' ';
        }
    }
    stringstream ss(s);
    string word;
    string res = "";
    bool isFirst = true;
    while (ss >> word){
        if (!isFirst){
            res += ' ';
        }
        res += word;
        if (isFirst){
            isFirst = false;
        }
    }
    cout << res << endl;
    return 0;
}