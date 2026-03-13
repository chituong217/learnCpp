#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    for (int i = 0; i < (int)s.size(); i++){
        s[i] = toupper(s[i]);
    }

    cout << s << endl;

    for (int i = 0; i < (int)s.size(); i++){
        s[i] = tolower(s[i]);
    }

    cout << s;
    
    return 0;
}