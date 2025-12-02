#include <stdio.h>

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	
	int res = -1, l = 0, r = n-1;
	while ( l <= r ){
		int m = (l + r)/2;
		if ( a[m] == x){
			res = m;
			r = m-1;
		}
		else if (a[m] < x){
			l = m+1;
		}
		else {
			r = m-1;
		}
	}
	int trai = res;
	printf("%d\n", res);
	
	res = -1; l = 0; r = n-1;
	while ( l <= r ){
		int m = (l + r)/2;
		if ( a[m] == x){
			res = m;
			l = m+1;
		}
		else if (a[m] < x){
			l = m+1;
		}
		else {
			r = m-1;
		}
	}
	int phai = res;
	printf("%d\n", res);
	
	res = -1; l = 0; r = n-1;
	while ( l <= r ){
		int m = (l + r)/2;
		if ( a[m] >= x){
			res = m;
			r = m-1;
		}
		else {
			l = m+1;
		}
	}
	printf("%d\n", res);
	
	res = -1; l = 0; r = n-1;
	while ( l <= r ){
		int m = (l + r)/2;
		if ( a[m] > x){
			res = m;
			r = m-1;
		}
		else {
			l = m+1;
		}
	}
	printf("%d\n", res);
	
	if (trai ==-1 || phai ==-1){
		printf("0");
	}
	else
		printf("%d\n", phai - trai +1);
	return 0;
}
