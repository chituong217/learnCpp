#include <stdio.h>
#define ll long long

int find(ll n){
	if (n<10) return n;
	else return find(n/10);
}

int main(){
	ll n;
	scanf("%lld", &n);
	printf("%d", find(n));
	return 0;
}
