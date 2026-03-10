#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?'){
            s[i] = ' ';
        }
    }

    vector<string> v;

    stringstream ss(s);
    string word;

    while (ss >> word){
        v.push_back(word);
    }

    int n = v.size();
    for (int i = 0; i < n; i++){
        cout << v[i];
        if (i != n - 1){
            cout << ' ';
        }
    }

    return 0;
}