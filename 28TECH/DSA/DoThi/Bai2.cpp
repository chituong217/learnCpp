#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

vector<pair<int,int>> dscanh;

int main(){
    int n;
    cin >> n;  
    cin.ignore(1);

    for (int i = 1; i <= n; i++){
        string s;
        getline(cin, s);

        stringstream ss(s);
        string number;
        while (ss >> number){
            int cuoi = stoi(number);
            if (i < cuoi){
                dscanh.push_back({i, cuoi});
            }
        }
    }

    sort(dscanh.begin(), dscanh.end());
    for (auto x : dscanh){
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}