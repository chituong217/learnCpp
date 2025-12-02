#include <stdio.h>
#include <algorithm>
#define ll long long

int f(ll n){
	if (n==1) return 0;
	int best= f(n-1);
	if (n%2==0) {
		int tmp= f(n/2);
		if (tmp<best) best =tmp;
	}
	if (n%3==0) {
		int tmp= f(n/3);
		if (tmp<best) best =tmp;
	}
	return 1+best;
}

int main(){
	ll n;
	scanf("%lld", &n);
	printf("%d", f(n));
}
