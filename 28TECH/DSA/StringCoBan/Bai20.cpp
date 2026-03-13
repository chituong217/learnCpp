#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

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

int main(){
    string s;
    getline(cin, s);

    vector<string> v;

    stringstream ss(s);
    string word;

    while (ss >> word){
        if (isReverseString(word) == true){
            v.push_back(word);
        }
    }

    sort(v.begin(), v.end());

    for (auto it : v){
        cout << it << ' ';
    }
    
    return 0;
}