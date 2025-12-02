#include <stdio.h>
#define ll long long
#include <algorithm>

int best(int n){
	if (n==3 || n==5) return 1;
	int x=1e9, y=1e9;
	if (n>0){
		x=1+best(n-3);
	}
	if (n>0){
		y=1+best(n-5);
	}
	return x<y? x:y;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", best(n));
	return 0;
}
