#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int find = -1;
    for (int i=n; i>0; i--){
        if (n%i==0 && i%2==1){
            find = i;
            break;
        }
    }
    cout << find;
    return 0;
}