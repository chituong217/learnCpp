#include <iostream>
#define MAX_LEN 100

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int n;
    cin >> n;
    
    int temp[MAX_LEN * MAX_LEN];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp[k]; 
            k++;
        }
    }

    int totalElements = n * n;
    for (int i = 0; i < totalElements - 1; i++) {
        for (int j = 0; j < totalElements - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }

    int result[MAX_LEN][MAX_LEN];
    int c1 = 0, h1 = 0, c2 = n - 1, h2 = n - 1;
    
    k = 0;
    
    while (h1 <= h2 && c1 <= c2) {
        for (int i = c1; i <= c2; i++) {
            result[h1][i] = temp[k];
            k++;
        }
        h1++;
        for (int i = h1; i <= h2; i++) {
            result[i][c2] = temp[k]; 
            k++;
        }
        c2--;
        if (h1 <= h2) {
            for (int i = c2; i >= c1; i--) {
                result[h2][i] = temp[k];
                k++;
            }
            h2--;
        }
        if (c1 <= c2) {
            for (int i = h2; i >= h1; i--) {
                result[i][c1] = temp[k];
                k++;
            }
            c1++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}