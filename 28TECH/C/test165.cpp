#include <stdio.h>

void giaohop(int a[], int b[], int m, int n){
	int giao[m+n], hop[m+n];
	int idxg=0, idxh=0;
	int i=0, j=0;
	while (i<m && j<n){
		if (a[i]==b[j]){
			hop[idxh++]=b[j++];
			giao[idxg++]= a[i++];
		}
		else if (a[i]<b[j]){
			hop[idxh++]=a[i++];
		}
		else {
			hop[idxh++]=b[j++];
		}
	}
	while (i<m){
		hop[idxh++]=a[i++];
	}
	while (j<n){
		hop[idxh++] = b[j++];
	}
	for (int i=0; i<idxh; i++){
		printf("%d ", hop[i]);
	}
	printf("\n");
	for (int i=0; i<idxg; i++){
		printf("%d ", giao[i]);
	}
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int a[m], b[n];
	for (int i=0; i<m; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	giaohop(a, b, m, n);
	return 0;
}
