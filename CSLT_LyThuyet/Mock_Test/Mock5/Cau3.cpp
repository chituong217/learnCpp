#include <iostream>

using namespace std;

void addBigNumbers(char* s1, char* s2){
    char result[1000] = "0";

    int nho = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2){
        strcat(result, s1);
    }
    else{
        strcat(result, s2);
    }

    int len = strlen(result);
    int i = len - 1;
    int i1 = len1 - 1;
    int i2 = len2 - 1;

    while (i1 >= 0 && i2 >= 0){
        int sum = 0;
        sum = atoi(s1[i1]) + atoi(s2[i2]);
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
        i--;
    }

    while (i1 >= 0){
        int sum = 0;
        sum = atoi(s1[i1]);
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
        i--;
    }

    while (i2 >= 0){
        int sum = 0;
        sum = atoi(s2[i2]);
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
        i--;
    }

    if (nho == 1){
        result[i] += 1;
        nho = 0;
    }

    if (result[0] == '0'){
        for (int k = 1; k < len; k++){
            cout << result[k];
        }
    }
    else{
        for (int k = 0; k < len; k++){
            cout << result[k];
        }
    }
}