#include <stdio.h>
#include <math.h>
#define ll long long

void inFibo(int n){
	ll Fibo1=0;
	ll Fibo2=1;
	ll Fibo;
	if (n==1){
		printf("%lld", Fibo1);
		return;
	}
	if (n==2){
		printf("%lld", Fibo2);
		return;
	}
	for (int i=3; i<=(n%1000000007); i++){
		Fibo= Fibo1 + Fibo2;
		if ((n%1000000007)==i){
			printf("%lld\n", Fibo);
			return;
		}
		Fibo1= Fibo2;
		Fibo2= Fibo;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	inFibo(n);
	return 0;
}
