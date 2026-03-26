#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// bài toán con chuột tìm mồi trong mê cung

int n;
int a[100][100];
string s = "";

void Try(int i, int j){
    if (i == n && j == n){
        // khi tới đích
        cout << s << " ";
    }


    // gán nước đi tiếp theo khi đang ở ô {i,j}
    if (i + 1 <= n && a[i + 1][j] == 1){
        // ô {i + 1, j} là đi xuống 1 ô
        // đảm bảo ô này vẫn hợp lệ và có thể đi được (==1)
        s += "D";
        a[i + 1][j] = 0; // đánh dấu con chuột đã đi qua ô này rồi
        Try(i + 1, j);
        s.pop_back(); // xóa nước đi đã đi khỏi xâu s
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
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        
        Try(1, 1);
        cout << endl;
    }

    return 0;
}