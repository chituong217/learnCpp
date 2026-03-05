#include <iostream>

using namespace std;

int ucln(int a, int b){
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool sntcn(int a, int b){
    if (ucln(a, b) == 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (sntcn(a[i], a[j]) == true){
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}