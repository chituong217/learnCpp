#include <iostream>
#include <string>

using namespace std;

string latnguoc(string s){
    string res;
    for (int i = s.size() - 1; i >= 0; i--){
        res.push_back(s[i]);
    }

    return res;
}

string inhoa(string s){
    string res;
    for (int i = 0; i < (int)s.size(); i++){
        res.push_back(toupper(s[i]));
    }

    return res;
}

string inthuong(string s){
    string res;
    for (int i = 0; i < (int)s.size(); i++){
        res.push_back(tolower(s[i]));
    }

    return res;
}

int main(){
    string s;
    getline(cin, s);

    cout << latnguoc(s) << endl;
    cout << inthuong(s) << endl;
    cout << inhoa(s) << endl;

    return 0;
}