#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k;
string s;
int n, cnt = 0;
vector<string> v;

void Try(int pos){
    for (int j = pos + 1; j < n; j++){
        if (s[j] > s[pos]){
            swap(s[j], s[pos]);
            cnt++;

            if (cnt <= k){
                v.push_back(s);
                Try(pos + 1);
            }

            swap(s[j], s[pos]);
            cnt--;
        }
        else{
            Try(pos + 1);
        }
    }
}

int main(){
    cin >> k;
    cin >> s;
    n = s.size();

    Try(0);
    sort(v.begin(), v.end());
    
    if (v.empty() == false){
        cout << *(v.rbegin());
    }
    else{
        cout << s;
    }

    return 0;
}