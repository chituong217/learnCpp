#include <stdio.h>

int b[1000000];
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++){
		int tmp=a[i];
		b[tmp]++;
	}
	int dem=0;
	for (int i=0; i<=1000000; i++){
		if (b[i] >=1) dem++;
	}
	printf("%d", dem);
	return 0;
}
