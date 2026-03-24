#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a(100);
bool isFinal = false;
int cnt = 1;

void khoitao(){
    a[1] = n;
}

void sinh(){
    int i = cnt;
    while (i >= 1 && a[i] == 1){
        i--;
    }  

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i]--;
        int d = cnt - i + 1;
        
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];

        for (int j = 1; j <= q; j++){
            a[i + j] = a[i];
            cnt++;
        }
        if (r != 0){
            cnt++;
            a[cnt] = r;
        }
    }
}

int main(){
    cin >> n;

    vector<vector<int>> v;

    int dem = 0;
    khoitao();
    while (isFinal == false){
        a[0] = cnt;
        v.push_back(a);
        dem++;
        sinh();
    }

    cout << dem << '\n';
    for (int i = 0; i < (int)v.size(); i++){
        int tmpCnt = v[i][0];
        for (int j = 1; j <= tmpCnt; j++){
            cout << v[i][j];
            if (j != tmpCnt){
                cout << '+';
            }
        }
        cout << '\n';
    }

    return 0;
}