#include <stdio.h>
int A[10000001]={0};
int B[10000001]={0};
int giao[10000001]={0};
int hop[10000001]={0};


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n], b[m];
	for (int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	int max1= -1e9, max2= -1e9;
	for (int i=0; i<n; i++){
		A[a[i]]++;
		if (a[i] > max1) max1=a[i];
	}
	for (int i=0; i<n; i++){
		B[b[i]]++;
		if (b[i] > max2) max2=b[i];
	}
	int min = max1<max2 ? max1 : max2;
	int max = max1>max2 ? max1 : max2;
	for (int i=0; i<=min; i++){
		if ( A[i] > 0 && B[i] > 0){
			giao[i]++;
			hop[i]++;
		}
		else if ((A[i]>0 && B[i]==0) || (A[i]==0 && B[i]>0)){
			hop[i]++;
		}
	}
	if (max1==max){
		for (int i=min+1; i<=max; i++){
			if (A[i]>0){
				hop[i]++;
			}
		}
	}
	else if (max2==max){
		for (int i=min+1; i<=max; i++){
			if (B[i]>0){
				hop[i]++;
			}
		}
	}
	for (int i=0; i<= max; i++){
		if (giao[i]>0){
			printf("%d ", i);
		}
	}
	printf("\n");
	for (int i=0; i<= max; i++){
		if (hop[i]>0){
			printf("%d ", i);
		}
	}
	return 0;
}
