#include <stdio.h>

void insertionSort(int a[], int n){
	for (int i=1; i<n; i++){
		int pos = i-1;
		int value = a[i];
		while (pos >=0 && value < a[pos]){
			a[pos +1] = a[pos];
			pos--;
		}
		a[pos +1] = value;
		
		printf("Buoc %d: ", (i));
		for (int k=0; k<n; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	insertionSort(a, n);
	return 0;
}
