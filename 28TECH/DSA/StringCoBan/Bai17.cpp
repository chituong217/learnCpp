#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    vector<string> v;

    stringstream ss(s);
    string word;

    while (ss >> word){
        v.push_back(word);
    }

    sort(v.begin(), v.end());
    for (auto it : v){
        cout << it << ' ';
    }

    cout << endl;

    sort(v.begin(), v.end(), greater<string>());
    for (auto it : v){
        cout << it << ' ';
    }

    return 0;
}