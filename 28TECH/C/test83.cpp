#include <stdio.h>
#include <math.h>
#define ll long long

void inFibo(ll n){
	ll Fibo1=1;
	ll Fibo2=1;
	ll Fibo;
	if (n==1) printf("%lld", Fibo1);
	for (int i=2; i<92; i++){
		Fibo= Fibo1 + Fibo2;
		if (Fibo>=n){
			printf("%lld", Fibo);
			return;
		}
		Fibo1= Fibo2;
		Fibo2= Fibo;
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	inFibo(n);
	return 0;
}
