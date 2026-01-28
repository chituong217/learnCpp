#include <iostream>
#include <map>

using namespace std;

int main(){
    map <char, int> mp;
    char tmp;
    while (cin >> tmp){
        mp[tmp]++;
    }
    int fremax = (*mp.begin()).second;
    int fremin = (*mp.rbegin()).second;
    for (auto it = mp.begin(); it != mp.end(); it++){
        if ((*it).second > fremax){
            fremax = (*it).second;
        }
        if ((*it).second < fremin){
            fremin = (*it).second;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++){
        if ((*it).second == fremax){
            cout << it->first << ' ' << it->second << endl;
            break;
        }
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        if ((*it).second == fremin){
            cout << it->first << ' ' << it->second << endl;
            break;
        }
    }
    cout << mp.size() << endl;

    return 0;
}