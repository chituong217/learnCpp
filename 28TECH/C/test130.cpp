#include <stdio.h>
#define ll long long


void day(ll a[], ll n, ll k){
	for (ll i=0; i<=n-k; i++){
		ll tong=0;
		for (ll j=i; j<i+k; j++){
			tong+=a[j];
		}
		printf("%lld ", tong);
	}
}


int main(){
	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	day(a, n, k);
	return 0;
}
