#include <stdio.h>
int c[10000001], d[10000001];
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int a[m], b[n];
	for (int i=0; i<m; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	int max=-1e9;
	for (int i=0; i<m; i++){
		c[a[i]]=1;
		if (a[i] > max) max= a[i];
	}
	for (int i=0; i<n; i++){
		d[b[i]]=1;
		if (b[i] > max) max = b[i];
	}
	
//	giao trong 2 mang a va b
	for (int i=0; i<=max; i++){
		if ( c[i]==1 && d[i]==1) printf("%d ", i);
	}
	printf("\n");
//	hop trong 2 mang a va b
	for (int i=0; i<=max; i++){
		if ( c[i]==1 || d[i]==1) printf("%d ", i);
	}
	return 0;
}
