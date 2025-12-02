#include <stdio.h>

void swap (int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(int a[], int n){
	for (int i=0; i<n-1; i++){
		printf("Buoc %d: ", (i+1));
		for (int k=0; k<n; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
		int minpos =i;
		for (int j=i+1; j<n; j++){
			if (a[j] < a[minpos]) {
				minpos = j;
			}
		}
		swap (&a[minpos], &a[i]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	selectionSort(a, n);
	return 0;
}
