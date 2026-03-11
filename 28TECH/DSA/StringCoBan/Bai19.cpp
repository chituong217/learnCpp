#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    set<string> se;

    stringstream ss(s);
    string word;

    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }

        se.insert(word);
    }

    cout << se.size();

    return 0;
}