#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    vector<string> v;

    stringstream ss(s);
    string word;

    while(ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }
        word[0] = toupper(word[0]);

        v.push_back(word);
    }

    int n = v.size();
    if (n == 0){
        return 0;
    }

    string name = v[n - 1];
    for (int i = 0; i < (int)name.size(); i++){
        name[i] = toupper(name[i]);
    }

    for (int i = 0; i < n - 1; i++){
        cout << v[i];
        if (i < n - 2){
            cout << ' ';
        }
        else{
            cout << ", ";
        }
    }
    cout << name << endl;
    
    cout << name << ", ";
    for (int i = 0; i < n - 1; i++){
        cout << v[i] << ' ';
    }

    return 0;
}