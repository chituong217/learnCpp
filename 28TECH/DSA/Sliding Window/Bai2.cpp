#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    multiset<int> se;

    for (int i = 0; i < k; i++){
        se.insert(a[i]);
    }

    if (se.empty() == false){
        cout << *(se.begin()) << ' ' << *(se.rbegin()) << '\n';
    }

    for (int i = k; i < n; i++){
        se.insert(a[i]);

        auto it = se.find(a[i - k]);
        if (it != se.end()){
            se.erase(it);
        }

        if (se.empty() == false){
            cout << *(se.begin()) << ' ' << *(se.rbegin()) << '\n';
        }
    }

    return 0;
}