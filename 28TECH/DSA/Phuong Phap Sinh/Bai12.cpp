#include <iostream>
#include <vector>

using namespace std;

int n, a[100], k;
int cnt = 0;
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
    isFinal = false;
}

void sinh(){
    int i = n;
    while (i >= 1 && a[i] == 1){
        cnt--;
        a[i] = 0;
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i] = 1;
        cnt++;
    }
}

bool check(){
    int cnt = 0;
    int i = 1;
    while (i <= n){
        if (a[i] == 1){
            int len = 0;
            while (i <= n && a[i] == 1){
                len++;
                i++;
            }
            if (len == k){
                cnt++;
            }
            else if (len > k){
                return false;
            }
        }
        else{
            i++;
        }
    }

    return cnt == 1;
}

int main(){
    cin >> n >> k;

    khoitao();
    while (isFinal == false){
        if (cnt == k){
            for (int i = 1; i <= n; i++){
                cout << a[i];
            }
            cout << ' ';
        }
        sinh();
    }

    cout << endl;

    khoitao();
    while (isFinal == false){
        if (check() == true){
            for (int i = 1; i <= n; i++){
                cout << a[i];
            }
            cout << ' ';
        }
        sinh();
    }

    return 0;
}