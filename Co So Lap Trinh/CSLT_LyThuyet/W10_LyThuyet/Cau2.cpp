// Tôi cam kết bài làm này là do tôi tự làm, ko phải nhờ người khác làm giùm, ko phải nhờ AI làm giùm

#include <iostream>

using namespace std;

// cau a
int sumSecret(int a[], int b[][100], int nrows, int ncols, int k){
    int sum = 0;

    for (int i = 0; i < nrows; i++){

        int foundStart = -1;

        for (int j = 0; j <= ncols - k; j++){
            bool isMatch = true;

            for (int x = 0; x < k; x++){
                if (b[i][j + x] != a[x]){
                    isMatch = false;
                    break;
                }
            }

            if (isMatch == true){
                foundStart = j;
                break;
            }
        }

        if (foundStart != -1){
            for (int j = 0; j < ncols; j++){
                if (j >= foundStart && j <= foundStart + k - 1) continue;
                sum += b[i][j];
            }

            return sum;
        }

    }

    return 0;
}

// cau b
int countMatch(int a[], int k, int b[][100], int nrows, int ncols){
    int cnt = 0;
    // xet ngang
    for (int i = 0; i < nrows; i++){
        // xet xuoi
        for (int j = 0; j < ncols - k + 1; j++){
            bool isMatch = true;
            for (int x = 0; x < k; x++){
                if (b[i][j + x] != a[x]){
                    isMatch = false;
                    break;
                }
            }

            if (isMatch == true){
                cnt++;
            }
        }

        // xet nguoc
        for (int j = ncols - 1; j >= k - 1; j--){
            bool isMatch = true;
            for (int x = 0; x < k; x++){
                if (b[i][j - x] != a[x]){
                    isMatch = false;
                    break;
                }
            }

            if (isMatch == true){
                cnt++;
            }
        }
        
    }

    // xet doc
    for (int j = 0; j < ncols; j++){
        // xet xuoi
        for (int i = 0; i < nrows - k + 1; i++){
            bool isMatch = true;
            for (int x = 0; x < k; x++){
                if (b[i + x][j] != a[x]){
                    isMatch = false;
                    break;
                }
            }

            if (isMatch == true){
                cnt++;
            }
        }
        
        // xet nguoc
        for (int i = nrows - 1; i >= k - 1; i--){
            bool isMatch = true;
            for (int x = 0; x < k; x++){
                if (b[i - x][j] != a[x]){
                    isMatch = false;
                    break;
                }
            }

            if (isMatch == true){
                cnt++;
            }
        }

    }

    return cnt;
}