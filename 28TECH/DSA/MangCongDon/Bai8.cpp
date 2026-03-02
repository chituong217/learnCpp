#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector < pair< pair<int,int>, int> > save_index (m);
    int index = 0;

    long long a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long D[n + 5] = {0};
    // D[0] = a[0];
    // for (int i = 1; i < n; i++){
    //     D[i] = a[i] - a[i - 1];
    // }

    for (int i = 0; i < m; i++){
        int left, right, d;
        cin >> left >> right >> d;

        left--; right--;
        save_index[index].first.first = left;
        save_index[index].first.second = right;
        save_index[index].second = d;
        index++;

        // D[left] += d;
        // D[right + 1] -= d;
    }

    long long fre_prefix[m + 5] = {0};
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;

        x--;y--;

        fre_prefix[x] += 1;
        fre_prefix[y + 1] -= 1;
    }

    long long fre[m + 5];

    fre[0] = fre_prefix[0];

    for (int i = 1; i < m; i++){
        fre[i] = fre[i - 1] + fre_prefix[i];
    }

    for (int i = 0; i < m; i++){
        if (fre[i] > 0){
            int left = save_index[i].first.first;
            int right = save_index[i].first.second;
            int d = save_index[i].second;

            D[left] += 1ll * d * fre[i];
            D[right + 1] -= 1ll * d * fre[i];
        }
    }

    // a[0] = D[0];
    // for (int i = 1; i < n; i++){
    //     a[i] = D[i] + a[i - 1];
    // }

    long long prefix[n + 5];
    prefix[0] = D[0];
    for (int i = 1; i < n; i++){
        prefix[i] = D[i] + prefix[i - 1];
    }

    long long a_moi[n + 5];
    for (int i = 0; i < n; i++){
        a_moi[i] = a[i] + prefix[i];
    }

    for (int i = 0; i < n; i++){
        cout << a_moi[i] << ' ';
    }

    return 0;
}