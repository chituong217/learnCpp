#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector<string> v;
vector<vector<string>> res;

bool check(string a){
    int left = 0, right = a.size() - 1;
    while (left <= right){
        if (a[left] != a[right]){
            return false;
        }
        left++;
        right--;
    }

    return true;
}

void Try(int start){
    if (start >= (int)s.size()){
        res.push_back(v);
    }

    for (int end = start; end < (int)s.size(); end++){
        if (check(s.substr(start, end - start + 1))){
            v.push_back(s.substr(start, end - start + 1));
            Try(end + 1);
            v.pop_back();
        }
    }
}

int main(){
    cin >> s;
    Try(0);

    for (auto it = res.begin(); it != res.end(); it++){
        for (auto it2 = it->begin(); it2 != it->end(); it2++){
            cout << *it2 << ' ';
        }
        cout << '\n';
    }

    return 0;
}