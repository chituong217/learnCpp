#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector<unsigned int>& mang, int n) {
    vector<unsigned int> mang_tam(n);
    for (int dich_bit = 0; dich_bit < 32; dich_bit = dich_bit + 8) {
        int dem[256];
        for (int i = 0; i < 256; i++) {
            dem[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            int chi_so = (mang[i] >> dich_bit) & 255;
            dem[chi_so] = dem[chi_so] + 1;
        }

        for (int i = 1; i < 256; i++) {
            dem[i] = dem[i] + dem[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int chi_so = (mang[i] >> dich_bit) & 255;
            dem[chi_so] = dem[chi_so] - 1;
            mang_tam[dem[chi_so]] = mang[i];
        }

        for (int i = 0; i < n; i++) {
            mang[i] = mang_tam[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<unsigned int> mang(n);
    int gia_tri;
    
    unsigned int bu_so = 2147483648; 

    for (int i = 0; i < n; i++) {
        cin >> gia_tri;
        mang[i] = gia_tri + bu_so;
    }

    radixSort(mang, n);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int gia_tri_goc = mang[i] - bu_so;
        cout << gia_tri_goc << "\n";
    }

    return 0;
}