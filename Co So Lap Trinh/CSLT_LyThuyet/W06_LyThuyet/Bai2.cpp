#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int comp(const void *a, const void *b){
    int *x = (int *)a;
    int *y = (int *)b;
    return *y - *x;
}

void xuli(char c[], int cnt[], int mark[], int &idx){
    for (int i=0; i < (int)strlen(c); i++){
        c[i] = tolower(c[i]);
    }

    for (int i=0; i < (int)strlen(c); i++){
        if (c[i] == ' '){
            continue;
        }
        int ma = (int)c[i];
        cnt[ma]++;
    }

    for (int i = 0; i < 128; i++){
        if (cnt[i] > 0){
            int check = 1;
            int fre = cnt[i];
            for (int j=0; j < idx; j++){
                if (mark[j] == fre){
                    check = 0;
                }
            }
            if (check == 1){
                mark[idx] = fre;
                idx++;
            }
        }
    }
}

int main(){
    char c[10001];
    cin.get(c, 10001, '\n');
    int cnt[128] = {0}, mark[101] = {0};
    int idx = 0;

    // for (int i=0; i < (int)strlen(c); i++){
    //     c[i] = tolower(c[i]);
    // }

    // for (int i=0; i < (int)strlen(c); i++){
    //     if (c[i] == ' '){
    //         continue;
    //     }
    //     int ma = (int)c[i];
    //     cnt[ma]++;
    // }


    // for (int i = 0; i < 128; i++){
    //     if (cnt[i] > 0){
    //         int check = 1;
    //         int fre = cnt[i];
    //         for (int j=0; j < idx; j++){
    //             if (mark[j] == fre){
    //                 check = 0;
    //             }
    //         }
    //         if (check == 1){
    //             mark[idx] = fre;
    //             idx++;
    //         }
    //     }
    // }

    xuli(c, cnt, mark, idx);

    qsort(mark, 101, sizeof(int), comp);

    for (int i=0; i < idx; i++){
        int fre = mark[i];
        cout << fre << ": ";
        for (int j=0; j < 128; j++){
            if (cnt[j] == fre){
                cout << (char)j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}