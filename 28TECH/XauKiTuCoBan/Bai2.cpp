#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

string reverseString(string s){
    string rev;
    int len = s.size();
    for (int i = len - 1; i >= 0; i--){
        rev.push_back(s[i]);
    }
    return rev;
}

string toLower(string s){
    string lower = s;
    int len = s.size();
    for (int i = 0; i < len; i++){
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

string toUpper(string s){
    string upper = s;
    int len = s.size();
    for (int i = 0; i < len; i++){
        upper[i] = toupper(upper[i]);
    }
    return upper;
}

int main(){
    string s;
    getline(cin, s);
    string rev = reverseString(s);
    string lower = toLower(s);
    string upper = toUpper(s);
    cout << rev << endl;
    cout << lower << endl;
    cout << upper << endl;
    
    return 0;
}