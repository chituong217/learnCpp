#include <stdio.h>

void up (int a[], int n){
	int idx=0;
	printf("%d ", a[idx]);
	for (int i=1; i<n; i++){
		if ( a[i] > a[idx]){
			printf("%d ", a[i]);
			idx = i;
		}
	}
}


int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	up(a, n);
	return 0;
}
