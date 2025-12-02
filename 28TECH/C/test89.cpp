#include <stdio.h>
#include <math.h>

long long gt(int n){
	if (n==0) return 1;
	else return n*gt(n-1);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", gt(n));
	return 0;
}
