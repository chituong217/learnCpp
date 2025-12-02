#include <stdio.h>

int first (int a[], int n, int x){
	int res = -1, l = 0, r = n-1;
	while (l <= r){
		int m = (l + r)/2;
		if (a[m] <= x){
			res = m;
			l = m+1;
		}
		else {
			r = m-1;
		}
	}
	return res;
}

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	int a[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d", first(a, n, x));
	return 0;
}
