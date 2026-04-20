#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> table(m, 0);
    const long long P = 53;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        long long h = 0;
        for (int j = 0; j < (int)s.size(); ++j) {
            h = (h * P + (unsigned char)s[j]) % m;
        }

        int initial_hash = (int)h;
        int jump = 0;
        int current_pos = initial_hash;

        while (jump < 5 && table[current_pos] > 0) {
            jump++;
            current_pos = (initial_hash + jump) % m;
        }

        cout << jump << " " << table[current_pos] << "\n";

        table[current_pos]++;
    }

    return 0;
}