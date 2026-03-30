#include <iostream>

using namespace std;

int n;
int X[100], visited[100];

void in(){
    for (int i = 1; i <= n; i++){
        cout << X[i];
    }
    cout << endl;
}

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (visited[j] == 0){
            if (i == 1){
                visited[j] = 1;
                X[i] = j;
                if (i == n){
                    in();
                }
                else{
                    Try(i + 1);
                }
            }
            else{
                if (abs(j - X[i - 1]) != 1){
                    visited[j] = 1;
                    X[i] = j;

                    if (i == n){
                        in();
                    }
                    else{
                        Try(i + 1);
                    }
                }
            }

            visited[j] = 0;
        }
    }
}

int main(){
    cin >> n;

    Try(1);

    return 0;
}