#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct canh{
    int dau, cuoi, w;
};

vector<canh> ds;

bool comp(canh a, canh b){
    return a.dau < b.dau;
}

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int w;
            cin >> w;

            if (w > 0){
                if (i < j){
                    canh tmp;
                    tmp.dau = i; tmp.cuoi = j; tmp.w = w;
                    ds.push_back(tmp);
                }
            }
        }
    }

    sort(ds.begin(), ds.end(), comp);

    for (auto it : ds){
        cout << it.dau << ' ' << it.cuoi << ' ' << it.w << '\n';
    }

    return 0;
}