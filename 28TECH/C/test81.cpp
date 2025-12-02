#include <stdio.h>
#include <math.h>
#define ll long long

void inFibo(int n){
	ll Fibo1=0;
	ll Fibo2=1;
	ll Fibo;
	if (n==1) printf("%lld", Fibo1);
	if (n>=2){
		printf("%lld\n%lld\n", Fibo1, Fibo2);	
	}
	for (int i=2; i<n; i++){
		Fibo= Fibo1 + Fibo2;
		printf("%lld\n", Fibo);
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
