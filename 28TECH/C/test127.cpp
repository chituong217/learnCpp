#include <stdio.h>
#define ll long long

int main(){
	ll n, x, k;
	scanf("%lld %lld %lld", &n, &x, &k);
	ll a[n+1];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	for (ll i=n; i>k-1; i--){
		a[i]= a[i-1];
	}
	a[k-1] =x;
	n++;
	for (ll i=0; i<n; i++){
		printf("%lld ", a[i]);
	}
	return 0;
}
