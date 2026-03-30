#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<string> se;

int n, a[100];
vector<int> X(1);

void Try(int i, int pos){
    for (int j = pos; j <= n; j++){
        if (a[j] > X[i - 1]){
            X.push_back(a[j]);

            if ((int)(X.size()) > 2){
                string s = "";
                for (int l = 1; l < (int)X.size(); l++){
                    s += to_string(X[l]);
                    if (l != (int)(X.size() - 1)){
                        s += ' ';
                    }
                }
                se.insert(s);
            }

            if (i != n){
                Try(i + 1, j + 1);
            }

            X.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    X[0] = 0;
    Try(1, 1);

    for (auto it = se.begin(); it != se.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}