#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    string t;
    getline(cin, t);

    string name = "";

    stringstream ss(s);
    string word;

    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }
        word[0] = toupper(word[0]);

        name += word;
        name += ' ';
    }

    string day = "", month = "", year = "";
    int slashNum = 0;
    for (int i = 0; i < (int)t.size(); i++){
        if (t[i] == '/'){
            slashNum++;
            continue;
        }
        
        if (slashNum == 0){
            day += t[i];
        }
        else if (slashNum == 1){
            month += t[i];
        }
        else{
            year += t[i];
        }
    }

    if (day.size() == 1){
        day += '0';
        reverse(day.begin(), day.end());
    }
    if (month.size() == 1){
        month += '0';
        reverse(month.begin(), month.end());
    }

    cout << name << endl;
    cout << day << '/' << month << '/' << year;

    return 0;
}