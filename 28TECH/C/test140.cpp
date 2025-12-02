#include <stdio.h>

int test(int a[], int n){
	if (n==0) return 1;
	if (a[n]>a[n-1]) return test(a, --n);
	else return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	if (test(a, n-1)==1) printf("YES");
	else printf("NO");
	return 0;
}

