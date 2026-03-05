#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    multiset <int> ms;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < k; i++){
        ms.insert(a[i]);
    }

    auto median = ms.begin();
    int mid;
    if (k % 2 == 0){
        mid = k / 2;
    }
    else{
        mid = (k + 1) / 2;
    }

    for (int i = 0; i < mid - 1; i++){
        median++;
    }

    cout << *median << ' ';

    for (int i = k; i < n; i++){
        ms.insert(a[i]);

        if (a[i] < *median){
            median--;
        }

        auto it = ms.find(a[i - k]);
        
        if (a[i - k] <= *median){
            if (it == median){
                median++;
                ms.erase(it);
            }
            else{
                ms.erase(it);
                median++;
            }
        }
        else{
            ms.erase(it);
        }
        
        cout << *median << ' ';
    }

    return 0;
}