#include <stdio.h>

int bS(int a[], int l, int r, int x){
	if (l <= r){
		int m = (l + r)/2;
		if (a[m] == x) return 1;
		else if (a[m] < x) return bS(a, l, m-1, x);
		else return bS(a, m+1, r, x);
	}
	else return 0;
}

int main(){
	int n, x;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	printf("%d", bS(a, 0, n-1, x));
	return 0;
}
