#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

bool isReverseString(string s){
    int left = 0, right = s.size() - 1;

    while (left <= right){
        if (s[left] != s[right]){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

bool comp(string a, string b){
    if (a.size() < b.size()){
        return true;
    }
    else if (a.size() == b.size()){
        return false;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    getline(cin, s);

    vector<string> v;
    set<string> se;
    
    stringstream ss(s);
    string word;

    while (ss >> word){
        if (isReverseString(word) == true && se.find(word) == se.end()){
            v.push_back(word);
            se.insert(word);
        }
    }

    stable_sort(v.begin(), v.end(), comp);
    for (auto it : v){
        cout << it << ' ';
    }

    return 0;
}