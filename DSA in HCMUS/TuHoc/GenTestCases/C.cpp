#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

void heapify(vector<string> &a, int left, int right){
    int p = left * 2 + 1;
    if (p > right) return;
    if (p + 1 <= right && cmp(a[p], a[p + 1])){
        p = p + 1;
    }

    if (cmp(a[left], a[p])){
        swap(a[left], a[p]);
        heapify(a, p, right);
    }
}

void createHeap(vector<string> &a, int n){
    for (int i = (n - 1)/2; i >= 0; i--){
        heapify(a, i, n - 1);
    }
}

void heapSort(vector<string> &a, int n){
    createHeap(a, n);

    for (int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, 0, i - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    heapSort(a, n);

    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }

    return 0;
}