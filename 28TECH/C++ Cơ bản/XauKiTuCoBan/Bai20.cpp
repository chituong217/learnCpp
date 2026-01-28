#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

bool isThuanNghich(string s){
    int left = 0, right = s.size() - 1;
    while (left <= right){
        if (s[left] != s[right]){
            return false;
        }
        left++; right--;
    }
    return true;
}

int main(){
    vector <string> v;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    while (ss >> word){
        if (isThuanNghich(word)){
            v.push_back(word);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}