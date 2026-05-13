#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> ke[n];

    for (int i = 0; i < m; i++){
        int dau, duoi;
        cin >> dau >> duoi;

        ke[dau - 1].push_back(duoi);
        ke[duoi - 1].push_back(dau);
    }

    for (int i = 0; i < n; i++){
        sort(ke[i].begin(), ke[i].end());
        cout << i + 1 << " : ";
        for (int x : ke[i]){
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}