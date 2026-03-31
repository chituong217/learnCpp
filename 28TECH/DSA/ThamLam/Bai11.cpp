#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solve() {
    long long k;
    string s;
    if (!(cin >> k >> s)) return;

    if (k >= (long long)s.size()) {
        cout << 0 << endl;
        return;
    }

    long long freq[300] = {0};
    for (char c : s) {
        freq[(int)c]++;
    }

    priority_queue<long long> pq;
    for (int i = 0; i < 300; i++) {
        if (freq[i] > 0) {
            pq.push(freq[i]);
        }
    }


    while (k > 0 && !pq.empty()) {
        long long top = pq.top();
        pq.pop();
        top--;
        k--;
        if (top > 0) pq.push(top);
    }

    long long res = 0;
    while (!pq.empty()) {
        long long top = pq.top();
        pq.pop();
        res += top * top;
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}