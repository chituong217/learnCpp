#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    map<string, int> mp;

    stringstream ss(s);
    string word;

    while(ss >> word){
        mp[word]++;
    }

    int minFre = INT_MAX, maxFre = INT_MIN;
    for (auto it = mp.begin(); it != mp.end(); it++){
        minFre = min(minFre, it->second);
        maxFre = max(maxFre, it->second);
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        if (it->second == maxFre){
            cout << it->first << ' ' << it->second << endl;
            break;
        }
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        if (it->second == minFre){
            cout << it->first << ' ' << it->second << endl;
            break;
        }
    }

    return 0;
}