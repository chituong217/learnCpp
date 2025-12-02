#include <stdio.h>

void inFibon(int n){
	if (n==1) printf("0 ");
	else if (n==2) printf("1 ");
	else {
		long long Fn2=0;
		long long Fn1=1;
		long long Fn;
		for (int i=2; i<=n; i++){
			Fn= Fn1 + Fn2;
			if (i == n){
				printf("%lld", Fn);
			}
			Fn2=Fn1;
			Fn1=Fn;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	inFibon(n);
	return 0;
}
