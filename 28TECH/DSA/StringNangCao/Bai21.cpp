#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);

    map<string, int> mp1, mp2;

    stringstream ss(s);
    string word;
    
    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }
        mp1[word]++;
    }

    stringstream ss2(t);

    while (ss2 >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }
        mp2[word]++;
    }

    for (auto it = mp1.begin(); it != mp1.end(); it++){
        if (mp2.find(it->first) != mp2.end()){
            cout << it->first << ' ';
        }
    }

    return 0;
}