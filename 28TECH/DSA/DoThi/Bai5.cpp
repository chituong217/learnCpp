#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> dscanh;
vector<int> ke[1005];

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int check;
            cin >> check;

            if (check == 1){
                if (i > j){
                    dscanh.push_back({i, j});
                }

                ke[i].push_back(j);
            }
        }
    }

    sort(dscanh.begin(), dscanh.end());
    for (auto it : dscanh){
        cout << it.first << ' ' << it.second << '\n';
    }

    cout << endl;

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
        cout << i << " : ";
        for (int x : ke[i]){
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}