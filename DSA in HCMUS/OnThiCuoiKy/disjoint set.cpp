#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int* parent;
    int* rank;
    int n;
};

void initDSU(DSU &dsu, int n);
int findSet(DSU &dsu, int i); // Nén đường đi đệ quy
bool unionSets(DSU &dsu, int i, int j); // Gộp theo hạng
void freeDSU(DSU &dsu);