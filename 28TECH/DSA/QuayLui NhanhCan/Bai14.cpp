#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<int> a(100);
vector<int> X;
vector<vector<int>> result;
int cnt = 0;

void in(vector<int> &X){
    auto beforeEnd = X.end();
    beforeEnd--;

    cout << "{";
    for (auto it = X.begin(); it != X.end(); it++){
        cout << *it;
        if (it != beforeEnd){
            cout << ' ';
        }
    }

    cout << "}";
}

void Try(int pos, int target){
    if (target == 0){
        result.push_back(X);
        cnt++;
        return;
    }

    for (int j = pos; j <= n; j++){
        if (a[j] <= target){
            X.push_back(a[j]);

            Try(j, target - a[j]);

            X.pop_back();
        }
        else{
            return;
        }
    }
}

int main(){
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a.begin() + 1, a.begin() + 1 + n);

    Try(1, x);
    
    if (cnt != 0){
        cout << cnt << '\n';
    }
    else{
        cout << "-1";
        return 0;
    }

    for (auto it = result.begin(); it != result.end(); it++){
        in(*it);
        cout << '\n';
    }

    return 0;
}