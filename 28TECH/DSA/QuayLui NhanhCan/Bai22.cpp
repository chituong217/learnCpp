#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int sum = 0;
bool found = false;
int X[100], visited[100];

void Try(int i){
    for (int j = X[i - 1] + 1; j <= 9; j++){
        if (visited[j] == 0){
            visited[j] = 1;
            X[i] = j;
            sum += j;

            if (i == k){
                if (sum == n){
                    found = true;
                    for (int l = 1; l <= k; l++){
                        cout << X[l];
                        if (l != k){
                            cout << " + ";
                        }
                    }
                    cout << '\n';
                }
            }
            else{
                if (sum < n){
                    Try(i + 1);
                }
            }

            sum -= j;
            visited[j] = 0;
        }
    }
}

int main(){
    cin >> n >> k;
    Try(1);

    if (found == false){
        cout << "NOT FOUND";
    }

    return 0;
}