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
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int i = 0, j = 0;
    long long cnt = 0;
    while (i < n){
        if (j >= m){
            break;
        }

        if (a[i] > b[j]){
            j++;
        }
        else if (a[i] < b[j]){
            i++;
        }
        else{
            int current_val = a[i];
            long long cntA = 0;
            long long cntB = 0;
            while (i < n && current_val == a[i]){
                cntA++;
                i++;
            }
            while (j < m && current_val == b[j]){
                cntB++;
                j++;
            }

            cnt += cntA * cntB;
        }

    }

    cout << cnt;

    return 0;
}