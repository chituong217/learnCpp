#include <iostream>

#include <string>

#include <map>



using namespace std;



int main(){

    string s;

    cin >> s;



    map<string,int> mp;



    string tmp;

    for (int i = 0; i < (int)s.size(); i++){

        if (i == 0){

            tmp += s[i];

        }

        else{

            if (s[i] != s[i - 1]){

                tmp += s[i];

            }

            else{

                mp[tmp] = tmp.size();

                tmp = "";

                tmp += s[i];

            }

        }

    }



    if (tmp != ""){

        mp[tmp] = tmp.size();

        tmp = "";

    }



    int maxLen = 0;

    for (auto it = mp.begin(); it != mp.end(); it++){

        maxLen = max(maxLen, it->second);

    }



    for (auto it = mp.rbegin(); it != mp.rend(); it++){

        if (it->second == maxLen){

            cout << it->first;

            break;

        }

    }



    return 0;

}