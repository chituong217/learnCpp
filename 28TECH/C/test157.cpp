#include <stdio.h>

void distance(int a[], int n){
	printf("%d %d\n", a[1]-a[0], a[n-1]-a[0]);
	for (int i=1; i<n-1; i++){
		printf("%d ", a[i]-a[i-1]<a[i+1]-a[i] ? a[i]-a[i-1] : a[i+1]-a[i]);
		printf("%d\n", a[i]-a[0]>a[n-1]-a[i]? a[i]-a[0] : a[n-1]-a[i]);
	}
	printf("%d %d", a[n-1]-a[n-2], a[n-1]-a[0]);
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	distance(a, n);
	return 0;
}
