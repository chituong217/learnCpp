#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n < 2){
        return false;
    }

    for (int i = 2; i*i < n; i++){
        if (n % i == 0){
            return false;
        }
    }

    return true;
}

void partitionPrimes(int* arr, int n){
    int left = 0;
    int right = n - 1;

    while (left < right){
        if (isPrime(arr[left]) == true && isPrime(arr[right]) == true){
            left++;
        }
        else if (isPrime(arr[left]) == false && isPrime(arr[left]) == true){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;

            left++;
            right--;
        }
        else if (isPrime(arr[left]) == false && isPrime(arr[right]) == false){
            right--;
        }
        else{
            left++;
            right--;
        }
    }
}