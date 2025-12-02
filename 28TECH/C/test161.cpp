#include <stdio.h>
int N[10000001];


int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int max=-1e9;
	for (int i=0; i<n; i++){
		N[a[i]]++;
		if (a[i]> max) max=a[i];
	}
	for (int i=0; i<=max; i++){
		if (N[i]>0){
			printf("%d %d\n", i, N[i]);
		}
	}
	printf("\n");
	for (int i=0; i<n; i++){
		if (N[a[i]]>0){
			printf("%d %d\n", a[i], N[a[i]]);
			N[a[i]]=0;
		}
	}
	return 0;
}
