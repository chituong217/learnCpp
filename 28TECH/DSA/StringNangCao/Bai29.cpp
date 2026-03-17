#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;

    long long sum = 0;

    for (int i = 0; i < (int)s.size(); i++){
        if (isdigit(s[i]) == 0){
            s[i] = ' ';
        }
    }

    stringstream ss(s);
    string word;

    vector<string> v;

    while (ss >> word){
        if (word.size() == 1 && s[0] == '0'){
            v.push_back(word);
            continue;
        }

        int i = 0, n = word.size();
        while (word[i] == '0'){
            if (i == n - 1){
                break;
            }
            i++;
        }

        string numberWithoutZero = word.substr(i);
        v.push_back(numberWithoutZero);
    }

    for (vector<string>::iterator it = v.begin(); it != v.end(); it++){
        sum += stoll(*it);
    }

    cout << sum;

    return 0;
}