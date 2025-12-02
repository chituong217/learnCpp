#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//	Khi x va y da dung thu tu tra ve so am, khi khong dung thu tu mong muon thi tra ve so duong.

int tong(int n){
	int sum=0; 
	while (n){
		sum+= n%10;
		n/=10;
	}
	return sum;
}

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y= (int *)b;
	return *x - *y;
}

int main(){
	int n;
	scanf("%d", &n);
	int *a = (int *) malloc (n * sizeof(int));
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	} 
	
	qsort (a, n, sizeof(n), comp);
	int min = 1e9;
	for (int i=1; i<n; i++){
		int tmp = abs(a[i] - a[i-1]);
		if (tmp < min) min = tmp;
	}
	printf("%d", min);
	return 0;
}
