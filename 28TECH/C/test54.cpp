#include <stdio.h>

void inFibo (int n){
	long long Fn2=0;
	long long Fn1=1;
	long long Fn=0;
	printf("%lld \n", Fn2);
	printf("%lld \n", Fn1);
	for (int i=0; i<n; i++){
		Fn= Fn2 + Fn1;
		printf("%lld \n", Fn);
		Fn2= Fn1;
		Fn1= Fn;
	}
}

int main (){
	int n;
	scanf("%d", &n);
	inFibo(n);
	return 0;
}
