#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int write = 0, read = 1;
    while (read < n){
        if (a[write] == a[read]){
            read++;
        }
        else{
            write++;
            a[write] = a[read];

            read++;
        }
    }

    for (int i = 0; i <= write; i++){
        cout << a[i] << ' ';
    }

    return 0;
}