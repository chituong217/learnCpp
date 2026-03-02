#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int j = 0; j < m; j++){
        cin >> b[j];
    }

    int idx_a = 0, cnt = 0;
    for (int i = 0; i < m; i++){
        while (idx_a < n && a[idx_a] < b[i]){
            idx_a++;
            cnt++;
        }

        cout << cnt << ' ';
    }

    return 0;
}