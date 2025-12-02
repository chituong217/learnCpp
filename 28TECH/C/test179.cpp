#include <stdio.h>

int main(){
    int n, d;
    if (scanf("%d %d", &n, &d) != 2) return 0;
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    long long cnt = 0;
    for (int i=1; i<n; i++){
        if (a[i] <= a[i-1]){
            int thieu = a[i-1]- a[i];           
            int need = (thieu + d) / d;         
            a[i] += need * d;
            cnt += need;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}

