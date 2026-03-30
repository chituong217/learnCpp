#include <iostream>
#include <string>

using namespace std;

int n;
int a[100][100];
string s = "";
bool isValid = false;

void Try(int i, int j){
    if (i == n && j == n){
        cout << s << endl;
        isValid = true;
    }

    if (i + 1 <= n && a[i + 1][j] == 1){
        s += "D";
        a[i + 1][j] = 0;
        Try(i + 1, j);

        s.pop_back();
        a[i + 1][j] = 1;
    }
    if (j + 1 <= n && a[i][j + 1] == 1){
        s += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1);

        s.pop_back();
        a[i][j + 1] = 1;
    }
}


int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    Try(1, 1);

    if (isValid == false){
        cout << "-1";
    }

    return 0;
}