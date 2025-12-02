#include <stdio.h>
#include <math.h>

long long Fibo(int n){
	if (n==1) return 0;
	else if (n==2) return 1;
	else return Fibo(n-1) + Fibo(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", Fibo(n));
	return 0;
}
