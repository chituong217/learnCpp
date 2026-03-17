#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool comp1(string a, string b){
    if (a.size() < b.size()){
        return true;
    }
    else if (a.size() == b.size()){
        return a < b;
    }
    else{
        return false;
    }
}

bool comp2(string a, string b){
    return a + b < b + a;
}

int main(){
    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); i++){
        if (isdigit(s[i]) == 0){
            s[i] = ' ';
        }
    }

    vector<string> v;

    stringstream ss(s);
    string word;

    while (ss >> word){
        if (word.size() == 1 && word[0] == '0'){
            v.push_back(word);
            continue;
        }

        int i = 0;
        int n = word.size();
        while (word[i] == '0'){
            if (i == n - 1){
                break;
            }
            i++;
        }

        string numWithout0 = word.substr(i);
        v.push_back(numWithout0);
    }

    sort(v.begin(), v.end(), comp2);

    for (auto it = v.rbegin(); it != v.rend(); it++){
        cout << *it;
    }

    return 0;
}