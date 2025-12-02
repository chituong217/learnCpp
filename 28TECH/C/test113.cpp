#include <stdio.h>
#include <math.h>

void in(int a[], int n){
	for (int i=0; i<n; i++){
		if (i==0) printf("%d ", a[i]);
		for(int j=0; j<=i-1; j++){
			if (a[i]==a[j]) break;
			if(j==i-1) printf("%d ", a[i]);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n;i++){
		scanf("%d", &a[i]);
	}
	in(a,n);
	return 0;
}
