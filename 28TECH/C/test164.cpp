#include <stdio.h>

int N[10000001]={0};


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
	int max= -1e9;
	
	for (int i=0; i<m; i++){
		N[a[i]]=1;
		if (a[i] > max) max = a[i];
	}
	
	for (int i=0; i<n; i++){
		++N[b[i]];
		if (b[i] > max) max = b[i];
	}
	
	int idx=0;
	
	for (int i=0; i<= max; i++){
		if (N[i]>=1){
			printf("%d ", i);
		}	
	}
	
	printf("\n");
	
	for (int i=0; i<= max; i++){
		if (N[i]==2){
			printf("%d ", i);
		}	
	}
	return 0;
}
