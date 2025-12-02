#include <stdio.h>
int N[10000001];
void countingSort(int a[], int n){
	for (int i=0; i<n; i++){
		N[a[i]]++;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	countingSort(a, n);
	int max=-1e9;
	for  (int i=0; i<n; i++){
		if (a[i]>max) max=a[i];
	}
	for (int i=0; i<=max; i++){
		while (N[i]){
			printf("%d ", i);
			--N[i];
		}
	}
	return 0;
}
