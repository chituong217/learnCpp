#include <stdio.h>

void nghich(int a[], int n){
	if (n<0) return;
	printf("%d ", a[n]);
	nghich(a, --n);
}

void thuan(int a[], int n, int i){
	if (i==n) return;
	printf("%d ", a[i]);
	thuan(a, n, ++i);
}


int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int i=0;
	thuan(a, n, i);
	printf("\n");
	nghich(a, n-1);
	return 0;
}
