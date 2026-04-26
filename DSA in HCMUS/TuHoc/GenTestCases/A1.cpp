#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector<unsigned int>& a, int n) {
    vector<unsigned int> temp(n);
    for (int shift = 0; shift < 32; shift += 8) {
        int count[256] = {0};
        
        for (int i = 0; i < n; ++i) {
            count[(a[i] >> shift) & 0xFF]++;
        }
        
        for (int i = 1; i < 256; ++i) {
            count[i] += count[i - 1];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            temp[--count[(a[i] >> shift) & 0xFF]] = a[i];
        }
        
        for (int i = 0; i < n; ++i) {
            a[i] = temp[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<unsigned int> a(n);
    int x;
    
    const unsigned int OFFSET = 0x80000000;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[i] = (unsigned int)x + OFFSET; 
    }

    radixSort(a, n);

    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        int original_x = (int)(a[i] - OFFSET);
        cout << original_x << "\n";
    }

    return 0;
}