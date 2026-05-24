#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> mang_chuoi;

void gop(vector<int>& mang_vi_tri, int trai, int giua, int phai) {
    int so_luong_trai = giua - trai + 1;
    int so_luong_phai = phai - giua;

    vector<int> mang_L(so_luong_trai);
    vector<int> mang_R(so_luong_phai);

    for (int i = 0; i < so_luong_trai; i++) {
        mang_L[i] = mang_vi_tri[trai + i];
    }
    for (int j = 0; j < so_luong_phai; j++) {
        mang_R[j] = mang_vi_tri[giua + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = trai;

    while (i < so_luong_trai && j < so_luong_phai) {
        if (mang_chuoi[mang_L[i]] < mang_chuoi[mang_R[j]]) {
            mang_vi_tri[k] = mang_L[i];
            i = i + 1;
        } else {
            mang_vi_tri[k] = mang_R[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < so_luong_trai) {
        mang_vi_tri[k] = mang_L[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < so_luong_phai) {
        mang_vi_tri[k] = mang_R[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(vector<int>& mang_vi_tri, int trai, int phai) {
    if (trai >= phai) {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    mergeSort(mang_vi_tri, trai, giua);
    mergeSort(mang_vi_tri, giua + 1, phai);
    gop(mang_vi_tri, trai, giua, phai);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    mang_chuoi.resize(n);
    vector<int> mang_vi_tri(n);

    for (int i = 0; i < n; i++) {
        cin >> mang_chuoi[i];
        mang_vi_tri[i] = i; 
    }

    mergeSort(mang_vi_tri, 0, n - 1);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << mang_chuoi[mang_vi_tri[i]] << "\n";
    }

    return 0;
}