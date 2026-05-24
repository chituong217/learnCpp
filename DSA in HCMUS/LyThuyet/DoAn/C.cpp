#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> mang_tam;

void gop_chuoi(vector<string>& mang, int trai, int giua, int phai) {
    int i = trai;
    int j = giua + 1;
    int k = trai;

    while (i <= giua && j <= phai) {
        if (mang[i] < mang[j]) {
            mang_tam[k] = mang[i];
            i = i + 1;
        } else {
            mang_tam[k] = mang[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= giua) {
        mang_tam[k] = mang[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= phai) {
        mang_tam[k] = mang[j];
        j = j + 1;
        k = k + 1;
    }

    for (int chi_so = trai; chi_so <= phai; chi_so = chi_so + 1) {
        mang[chi_so] = mang_tam[chi_so];
    }
}

void mergeSortChuoi(vector<string>& mang, int trai, int phai) {
    if (trai >= phai) {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    mergeSortChuoi(mang, trai, giua);
    mergeSortChuoi(mang, giua + 1, phai);
    gop_chuoi(mang, trai, giua, phai);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> cac_ro[205];
    string chuoi_nhap;

    for (int i = 0; i < n; i++) {
        cin >> chuoi_nhap;
        int chieu_dai = chuoi_nhap.length();
        if (chieu_dai <= 200) {
            cac_ro[chieu_dai].push_back(chuoi_nhap);
        }
    }

    mang_tam.resize(n);

    cout << n << "\n";

    for (int do_dai = 0; do_dai <= 200; do_dai = do_dai + 1) {
        int kich_thuoc_ro = cac_ro[do_dai].size();
        if (kich_thuoc_ro > 0) {
            mergeSortChuoi(cac_ro[do_dai], 0, kich_thuoc_ro - 1);
            
            for (int i = 0; i < kich_thuoc_ro; i = i + 1) {
                cout << cac_ro[do_dai][i] << "\n";
            }
        }
    }

    return 0;
}