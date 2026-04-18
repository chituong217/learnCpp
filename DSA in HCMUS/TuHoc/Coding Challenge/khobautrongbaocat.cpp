#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DoVat {
    long long w, v;
};

bool comp(DoVat a, DoVat b) {
    return a.w < b.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long W;
    cin >> n >> W;

    vector<DoVat> a(n);
    long long res = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].v;
        if (a[i].v > res) res = a[i].v;
    }

    sort(a.begin(), a.end(), comp);

    vector<long long> p(n);
    p[0] = a[0].v;
    for (int i = 1; i < n; i++) {
        p[i] = max(p[i - 1], a[i].v);
    }

    for (int i = 0; i < n; i++) {
        long long khadung = W - a[i].w;
        
        int j = upper_bound(a.begin(), a.begin() + i, DoVat{khadung, 0}, comp) - a.begin() - 1;

        if (j >= 0) {
            if (j == i) j--;
            
            if (j >= 0) {
                if (a[i].v + p[j] > res) {
                    res = a[i].v + p[j];
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}