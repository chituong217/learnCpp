#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int l, r;
    cin >> l >> r;
    for (vector<int>::iterator it = v.begin() + l; it != v.begin() + r + 1; it++){
        cout << *it << ' ';
    }
    cout << endl;
    for (vector<int>::iterator it = v.begin() + r; it != v.begin() + l - 1; it--){
        cout << *it << ' ';
    }
    return 0;
}