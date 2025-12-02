#include <stdio.h>
#define ll long long

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	ll b[1001];
	for (ll i=0; i<n; i++){
		b[i]= a[n-1-i];
	}
	for (ll i=0; i<n; i++){
		printf("%lld ", b[i]);
	}
	return 0;
}
