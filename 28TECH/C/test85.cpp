#include <stdio.h>
#include <math.h>
#define ll long long

void ktFibo(ll n){
	if (n==0 || n==1) {
		printf("YES\n");
		return;
	}
	ll Fibo1=0;
	ll Fibo2=1;
	ll Fibo;
	for (int i=2; i<=92; i++){
		Fibo= Fibo1 + Fibo2;
		if (n==Fibo) {
			printf("YES\n");
			return;
		}
		Fibo1= Fibo2;
		Fibo2= Fibo;
	}
	printf("NO\n");
}

int main(){
	int t;
	ll n;
	scanf("%d", &t);
	while (t){
		scanf("%lld", &n);
		ktFibo(n);
		t--;
	}
	return 0;
}
