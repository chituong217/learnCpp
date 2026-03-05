#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector <int> odd, even;
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            even.push_back(a[i]);
        }
        else{
            odd.push_back(a[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    for (auto it = odd.begin(); it != odd.end(); it++){
        cout << *it << ' ';
    }
    for (auto it = even.begin(); it != even.end(); it++){
        cout << *it << ' ';
    }
    return 0;
}
