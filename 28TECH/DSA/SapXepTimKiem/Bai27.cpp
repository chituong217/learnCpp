#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> v(a.begin(), a.end());
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        auto it = upper_bound(v.begin(), v.end(), a[i]);

        if (it == v.end()){
            a[i] = 0;
        }
        else{
            a[i] = *it;
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] == 0){
            cout << '_' << ' ';
        }
        else{
            cout << a[i] << ' ';
        }
    }

    return 0;
}