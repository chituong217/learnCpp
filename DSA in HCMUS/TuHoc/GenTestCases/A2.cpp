#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>

using namespace std;

inline int readInt() {
    int x = 0, c = getchar();
    bool neg = false;

    while (c < '0' || c > '9') {
        if (c == '-') neg = true;
        c = getchar();
    }

    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return neg ? -x : x;
}

char out_buf[20];

inline void writeInt(int x) {
    if (x == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    int len = 0;
    while (x > 0) {
        out_buf[len++] = (x % 10) + '0';
        x /= 10;
    }
    while (len--) {
        putchar(out_buf[len]);
    }
    putchar('\n');
}

void ultraRadixSort(vector<unsigned int>& a, int n) {
    vector<unsigned int> temp(n);
    int count0[65536] = {0};
    int count1[65536] = {0};
    
    for (int i = 0; i < n; ++i) {
        count0[a[i] & 0xFFFF]++;
        count1[(a[i] >> 16) & 0xFFFF]++;
    }
    
    for (int i = 1; i < 65536; ++i) {
        count0[i] += count0[i - 1];
        count1[i] += count1[i - 1];
    }
    
    for (int i = n - 1; i >= 0; --i) {
        temp[--count0[a[i] & 0xFFFF]] = a[i];
    }
    
    for (int i = n - 1; i >= 0; --i) {
        a[--count1[(temp[i] >> 16) & 0xFFFF]] = temp[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = readInt();

    vector<unsigned int> a(n);
    const unsigned int OFFSET = 0x80000000;
    
    for (int i = 0; i < n; ++i) {
        a[i] = (unsigned int)readInt() + OFFSET; 
    }

    ultraRadixSort(a, n);

    writeInt(n);
    for (int i = 0; i < n; ++i) {
        int original_x = (int)(a[i] - OFFSET);
        writeInt(original_x);
    }

    return 0;
}