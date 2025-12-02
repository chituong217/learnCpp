#include <stdio.h>

void swap (int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int a[], int n){
	int res =n;
	int cnt =1;
	while (res>1){
		for (int i=1; i<res; i++){
			if ( a[i] < a[i-1]){
				swap( &a[i], &a[i-1]);
			}
		}
		res--;
		printf("Buoc %d: ", (cnt));
		for (int k=0; k<n; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
		
		cnt++;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	bubbleSort(a, n);
	return 0;
}
