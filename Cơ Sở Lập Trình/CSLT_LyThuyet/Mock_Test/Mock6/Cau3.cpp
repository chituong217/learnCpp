#include <iostream>
#include <cstring>

using namespace std;

void addBigNumbers(char* s1, char* s2){
    int nho = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int result[1000] = {0};

    int i = 0;
    int i1 = len1 - 1;
    int i2 = len2 - 1;

    while (i1 >= 0 && i2 >= 0){
        int sum = 0;
        sum = s1[i1] - '0' + s2[i2] - '0';

        if (nho == 1){
            sum += 1;
            nho = 0;
        }
        if (sum >= 10){
            nho = 1;
            sum -= 10;
        }

        result[i] = sum;

        i1--;
        i2--;
        i++;
    }

    while (i1 >= 0){
        int sum = 0;
        sum = s1[i1] - '0';
        if (nho == 1){
            sum += 1;
            nho = 0;
        }
        if (sum >= 10){
            nho = 1;
            sum -= 10;
        }
        result[i] = sum;
        
        i1--;
        i++;
    }

    while (i2 >= 0){
        int sum = 0;
        sum = s2[i2] - '0';
        if (nho == 1){
            sum += 1;
            nho = 0;
        }
        if (sum >= 10){
            nho = 1;
            sum -= 10;
        }
        result[i] = sum;
        
        i2--;
        i++;
    }

    if (nho == 1){
        result[i] = 1;
        nho = 0;
    }

    if (result[i] == 0){
        for (int k = i - 1 ; k >= 0; k--){
            cout << result[k];
        }
    }
    else{
        for (int k = i; k >= 0; k--){
            cout << result[k];
        }
    }
}
