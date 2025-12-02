#include <stdio.h>

int b[1000001];
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int maxval= -1e6;
	for (int i=0; i<n; i++){
		b[a[i]]++;
		if( a[i]>maxval) maxval=a[i];
	}
	int max=-1e9;
	int gt=0;
	for (int i=0; i<= maxval; i++){
		if (b[i]==max){
			if (i<gt) gt=i;
		}
		if (b[i]>max){
			max= b[i];
			gt=i;
		}
	}
	
	printf("%d %d", gt, max);
	return 0;
}
