#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    stringstream ss(s);
    stringstream countWord(s);
    string word;

    int cnt = 0;

    while (countWord >> word){
        cnt++;
    }

    int idx = 0;

    while (ss >> word){
        if (idx % 2 == 0){
            cout << word;
        }
        else{
            reverse(word.begin(), word.end());
            cout << word;
        }


        idx++;
        if (idx != cnt){
            cout << ' ';
        }
    }

    return 0;
}