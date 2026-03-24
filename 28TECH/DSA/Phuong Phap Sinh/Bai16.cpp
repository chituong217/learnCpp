#include <iostream>
#include <set>

using namespace std;

int n, k;
int a[1005];
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= k; i++){
        a[i] = i;
    }   
    isFinal = false;
}

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i]++;
        for (int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}

int main(){
    cin >> n >> k;

    set<int> se;
    for (int i = 1; i <= k; i++){
        cin >> a[i];
        se.insert(a[i]);
    }
    sinh();

    int cnt = 0;
    if (isFinal == true){
        cnt = k;
    }
    else{
        for (int i = 1; i <= k; i++){
            if (se.find(a[i]) == se.end()){
                cnt++;
            }
        }
    }
    
    cout << cnt;

    return 0;
}