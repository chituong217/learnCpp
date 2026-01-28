#include <iostream>
#define MAX_LEN 1000

using namespace std;

bool linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    int a[MAX_LEN], b[MAX_LEN];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char separator; 
    cin >> separator;

    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }

    int ans[MAX_LEN];
    int idx = 0;
    for (int i = 0; i < m; i++) {
        if (linearSearch(a, n, b[i])) { 
            ans[idx] = b[i];
            idx++;
        }
    }
    
    for (int i = 0; i < idx; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}