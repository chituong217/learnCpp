#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

string trim(const string& s) {
    size_t first = s.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, (last - first + 1));
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        
        size_t pos = line.find('-');
        
        string team_a = line.substr(0, pos);
        string team_b = line.substr(pos + 1);

        string x = trim(team_a);
        string y = trim(team_b);

        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    for (auto it = mp.begin(); it != mp.end(); it++){
        sort(it->second.begin(), it->second.end());
        
        cout << it->first << " : ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2;
            
            auto check = it2;
            check++;
            if (check != it->second.end()){
                cout << ", ";
            }
        }
        cout << endl;
    }

    

    return 0;
}