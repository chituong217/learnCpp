#include <iostream>
#include <string>

using namespace std;

int n, m;
char a[100][100];
bool visited[100][100];
string s;
bool found = false;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void Try(int i, int j, int pos){
    if (found == true){
        return;
    }

    if (pos == (int)s.size()){
        found = true;
        return;
    }
    
    for (int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if (i1 > 0 && i1 <= n && j1 > 0 && j1 <= m && visited[i1][j1] == false){
            if (a[i1][j1] == s[pos]){
                visited[i1][j1] = true;

                Try(i1, j1, pos + 1);

                visited[i1][j1] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> s;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == s[0]){
                visited[i][j] = true;
                Try(i, j, 1);
                visited[i][j] = false;

                if (found) break;
            }
        }
        if (found) break;
    }
    if (found == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}