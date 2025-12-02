#include <stdio.h>

int soFibo(long long n){
	if (n==1 || n==0) return 1;
	long long Fn2= 0;
	long long Fn1= 1;
	for (int i=2; i<=92; i++){
		long long Fn= Fn2+ Fn1;
		if (Fn == n) return 1;
		Fn2= Fn1;
		Fn1= Fn;
	}
	return 0;
}

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%d", soFibo(n));
	return 0;
}
