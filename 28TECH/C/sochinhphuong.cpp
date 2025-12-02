#include <stdio.h>
#include <math.h>

int scp(long long n){
	int can = sqrt(n);
	return can * sqrt(n) == n;
}

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%d", scp(n));
	return 0;
}
