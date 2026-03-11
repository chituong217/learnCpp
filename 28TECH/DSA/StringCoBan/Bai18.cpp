#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    if (a.size() > b.size()){
        return false;
    }
    else if (a.size() == b.size()){
        if (a < b){
            return true;
        }
        else{
            return false;
        }
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

    sort(v.begin(), v.end(), comp);

    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it << ' ';
    }

    return 0;
}