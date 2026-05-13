#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
    }

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
        cout << i << " : ";
        for (int it : ke[i]){
            cout << it << ' ';
        }
        cout << '\n';
    }


    return 0;
}