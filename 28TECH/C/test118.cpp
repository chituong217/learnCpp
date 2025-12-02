#include <stdio.h>
#define ll long long
#define mod 1000000007

ll tong(ll a[], ll n){
	ll tong=0;
	for (ll i=0; i<n; i++){
		tong += a[i];
		tong %= mod;
	}
	return tong;
}

ll tich(ll a[], ll n){
	ll tich=1;
	for (ll i=0; i<n; i++){
		tich*=a[i];
		tich %= mod;
	}
	return tich;
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	printf("%lld\n%lld", tong(a, n), tich(a, n));
	return 0;
}
