#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    if (a < b){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    vector <string> v;
    int idx = 0;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    while (ss >> word){
        v.push_back(word);
        idx++;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < idx; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
    for (int i = idx - 1; i >= 0; i--){
        cout << v[i] << ' ';
    }

    return 0;
}