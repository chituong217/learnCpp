#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> mp;

    while (n--){
        string s;
        getline(cin, s);

        vector<string> v;

        string mail = "";
        string password = "";

        stringstream ss(s);
        string word;
        while (ss >> word){
            v.push_back(word);
        }

        int vectorNum = v.size();
        string name = v[vectorNum - 2];
        for (int i = 0; i < (int)name.size(); i++){
            name[i] = tolower(name[i]);
        }

        mail += name;
        for (int i = 0; i < vectorNum - 2; i++){
            mail += tolower((v[i])[0]);
        }

        if (mp.find(mail) != mp.end()){
            mp[mail]++;
            mail += to_string(mp[mail]);
        }
        else{
            mp[mail] = 1;
        }
        mail += "@xyz.edu.vn";

        string date = v[vectorNum - 1];
        int day, month, year;
        char slash;

        stringstream ss2(date);
        ss2 >> day >> slash >> month >> slash >> year;

        password = to_string(day) + to_string(month) + to_string(year);

        cout << mail << endl;
        cout << password << endl;
    }

    return 0;
}