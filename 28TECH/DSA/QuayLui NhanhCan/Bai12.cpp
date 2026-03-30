#include <iostream>

using namespace std;

int n, a[100], sum = 0;
int cntSubSet = 0;
int visited[100];
int valid = 0;

void Try(int pos, int currSum){
    if (cntSubSet == 2){
        valid = 1;
        return;
    }

    if (currSum == sum){
        Try(1, 0);
    }

    for (int j = pos; j <= n; j++){
        if (visited[a[j]] == 0){
            currSum += a[j];
            visited[a[j]] = 1;

            if (currSum == sum){
                cntSubSet++;
                Try(1, 0);
            }
            else{
                Try(j + 1, currSum);
            }

            currSum -= a[j];
            visited[a[j]] = 0;
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 != 0){
        cout << "0";
    }
    else{
        sum /= 2;
        Try(1, 0);
        cout << valid;
    }

    return 0;
}