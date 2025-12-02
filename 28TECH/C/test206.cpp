#include <stdio.h>
#include <math.h>
void swap (int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int snt(int n){
	for(int i=2; i<=sqrt(n); i++){
		if (n%i==0)
			return 0;
	}
	return n>1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n][n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int cnt=0;
	for (int i=0; i<n; i++){
		if (snt(a[i][i]))
			cnt++;
	}
	
	for (int i=0; i<n; i++){
		if (snt(a[i][n-1-i]))
			cnt++;
	}
	if (n % 2 ==1){
		if (snt(a[(n-1)/2][(n-1)/2]))
			cnt--;
	}
	printf("%d", cnt);
	return 0;
}
