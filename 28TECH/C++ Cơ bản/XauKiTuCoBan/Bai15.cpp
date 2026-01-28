#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string reverseString(string s){
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--){
        res += s[i];
    }
    return res;
}

int main(){
    string s;
    getline(cin, s);
    int idx = 1;
    stringstream ss(s);
    string word;
    while (ss >> word){
        if (idx % 2 == 0){
            string reverse = reverseString(word);
            cout << ' ' << reverse;
        }
        else if (idx == 1){
            cout << word;
        }
        else{
            cout << ' ' << word;
        }
        idx++;
    }

    return 0;
}