#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    vector<string> v;
    map<string, int> mp;

    stringstream ss(s);
    string word;

    while(ss >> word){
        v.push_back(word);
        mp[word]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << ' ' << it->second << endl;
    }

    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++){
        if (mp[*it] > 0){
            cout << *it << ' ' << mp[*it] << endl;
            mp[*it] = 0;
        }
    }

    return 0;
}