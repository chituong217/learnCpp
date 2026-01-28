#include <iostream>
#define MAX_LEN 100

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i = n-1; i>=0; i--){
        cout << a[i] << " ";
    }
    return 0;
}