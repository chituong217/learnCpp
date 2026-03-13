#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

bool comp(string a, string b){
    if (a.size() > b.size()){
        return false;
    }
    else if (a.size() == b.size()){
        return a < b;
    }
    else{
        return true;
    }
}

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
    for (auto i : v){
        cout << i << ' ';
    }

    cout << endl;

    sort(v.begin(), v.end(), comp);
    for (auto i : v){
        cout << i << ' ';
    }

    return 0;
}