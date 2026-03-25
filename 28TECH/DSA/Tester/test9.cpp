#include <iostream>

using namespace std;

int n, X[100];
bool visited[100] = {false};

void in(){
    for (int i = 1; i <= n; i++){
        cout << X[i];
    }
}

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (visited[j] == false){
            X[i] = j;
            visited[j] = true;

            if (i == n){
                in();
                cout << endl;
            }
            else{
                Try(i + 1);
            }

            visited[j] = false;
        }
    }
}

int main(){
    cin >> n;

    Try(1);

    return 0;
}