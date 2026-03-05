#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    multiset<int> ms;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < k; i++){
        ms.insert(a[i]);
    }

    if (ms.empty() == false){
        cout << *(ms.begin()) << ' ' << *(ms.rbegin()) << '\n';
    }

    for (int i = k; i < n; i++){
        ms.insert(a[i]);

        auto it = ms.find(a[i - k]);
        if (it != ms.end()){
            ms.erase(it);
        }

        if (ms.empty() == false){
            cout << *(ms.begin()) << ' ' << *(ms.rbegin()) << '\n';
        }
    }

    return 0;
}