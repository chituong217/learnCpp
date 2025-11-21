#include <iostream>

#include <iomanip>

#include <cmath>

#define MAX_LEN 1000

using namespace std;





int main(){

    int n;

    cin >> n;

    int a[MAX_LEN];

    for (int i=0; i<n; i++){

        cin >> a[i];

    }

    int k; cin >> k;

    int cnt = 0;

   

    for (int i=0; i<n; i++){

        int bu = k - a[i];

        for (int j = i+1; j<n; j++){

            if (a[j] == bu){

                cnt++;

            }

        }

    }



    cout << cnt;

    return 0;

}