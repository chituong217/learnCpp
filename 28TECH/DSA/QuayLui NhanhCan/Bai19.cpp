#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[100];
vector<int> X;
vector<vector<int>> res;


void Try(int i, int sum){
    if (i == n + 1){
        if (sum % 2 != 0){
            res.push_back(X);
        }
        return;
    }

    Try(i + 1, sum);
    
    X.push_back(a[i]);
    Try(i + 1, sum + a[i]);

    X.pop_back();
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    Try(1, 0);

    if (res.size() == 0){
        cout << "NOT FOUND";
    }
    else{
        sort(res.begin(), res.end());
        for (auto it = res.begin(); it != res.end(); it++){
            for (auto it2 = it->begin(); it2 != it->end(); it2++){
                cout << *it2 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}