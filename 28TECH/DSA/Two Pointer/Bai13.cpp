#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int x, y;
    cin >> x >> y;

    int cnt2 = 0, cnt8 = 0;
    int maxLen = 0, currLen = 0;

    int start = 0;
    for (int end = 0; end < (int)s.size(); end++){
        if (s[end] == '2'){
            cnt2++;
        }
        else if (s[end] == '8'){
            cnt8++;
        }
        currLen++;

        while (cnt2 > x || cnt8 > y){
            if (s[start] == '2'){
                cnt2--;
            }
            else if (s[start] == '8'){
                cnt8--;
            }

            start++;
            currLen--;
        }

        if (cnt2 <= x && cnt8 <= y){
            if (currLen > maxLen){
                maxLen = currLen;
            }
        }
    }

    cout << maxLen;

    return 0;
}