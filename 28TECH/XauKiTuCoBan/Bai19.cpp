#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main(){
    set <string> se;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }
        se.insert(word);
    }
    cout << se.size() << endl;
    return 0;
}