#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    int res = 2;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> candidates;
        for (int h = 0; h < i; h++) {
            candidates.push_back({a[h], dp[h][i]});
        }

        sort(candidates.begin(), candidates.end());

        for (int k = 1; k < (int)candidates.size(); k++) {
            candidates[k].second = max(candidates[k].second, candidates[k - 1].second);
        }

        for (int j = i + 1; j < n; j++) {
            auto it = lower_bound(candidates.begin(), candidates.end(), make_pair(a[j], 0));
            
            if (it != candidates.begin()) {
                it--;
                dp[i][j] = it->second + 1;
            }

            if (dp[i][j] > res) res = dp[i][j];
        }
    }

    cout << res << endl;

    return 0;
}