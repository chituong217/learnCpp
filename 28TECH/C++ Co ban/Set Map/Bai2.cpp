#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }    
    sort(v.begin(), v.end());
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        bool found = binary_search(v.begin(), v.end(), x);
        if (found == true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}