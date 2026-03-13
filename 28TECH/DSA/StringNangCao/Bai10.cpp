#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    map <string, int> mp;
    vector <string> v;

    stringstream ss(s);
    string word;

    while (ss >> word){
        mp[word]++;
        v.push_back(word);
    }

    int cnt = mp.size();
    int dem = 0;

    for (auto it = mp.begin(); it != mp.end(); it++){
        dem++;
        cout << it->first;

        if (dem != cnt){
            cout << ' ';
        }
    }

    dem = 0;
    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++){
        if (mp[*it] > 0){
            mp[*it] = 0;
            cout << *it;
            dem++;

            if (dem != cnt){
                cout << ' ';
            }
        }
    }

    return 0;
}