#include <stdio.h>
#define ll long long

int f(ll n){
	if (n==1) return 0;
	int first = f(n-1);
	if (n%2==0) {
		if(f(n/2)<first) first = f(n/2);
	}
	if (n%3==0) {
		if(f(n/3)<first) first = f(n/3);
	}
	return 1+ first;
}

int main(){
	ll n;
	scanf("%lld", &n);
	printf("%d", f(n));
	return 0;
}
