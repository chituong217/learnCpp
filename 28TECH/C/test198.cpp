#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if ( *x < *y)
		return -1;
	else 
		return 1;
}


int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	long long cnt=0;
	qsort(a, n, sizeof(int), comp);
	for (int i=0; i<n; i++){
		int l=i+1, r=n-1, start=0, x = k - a[i];
		while ( l <= r){
			int m = (l + r)/2;
			if ( a[m] > x) {
				start = m;
				r=m-1;
			}
			else{
				l = m+1;
			}
		}
	
		l=i+1, r=n-1, x = k - a[i];
		int end = 0;
		while ( l <= r){
			int m = (l + r)/2;
			if ( a[m] > x) {
				end = m;
				l = m+1;
			}
			else {
				l = m+1;
		}
		}
		if ( start==0 && end ==0) continue;
		cnt += ( end - start +1);
	}
	
	
	printf("%lld", cnt);
	return 0;
}

