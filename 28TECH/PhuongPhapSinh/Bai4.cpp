#include <iostream>
#include <cstring>

using namespace std;

void ktao(int n, char c[]){
    for (int i=1; i <= n; i++){
        c[i] = 'B';
    }
}

void sinh(int n, char c[], bool &final){
    int i = n;
    while (i > 0 && c[i] == 'A'){
        c[i] = 'B';
        i--;
    }
    if (i == 0){
        final = true;
    }
    c[i] = 'A';
}


int main(){
    int n;
    cin >> n;
    char c[n+1];
    bool final = false;
    ktao(n, c);
    while( final == false){
        for (int i=1; i <= n; i++){
            cout << c[i];
        }
        cout << endl;
        sinh(n, c, final);
    }
    return 0;
}