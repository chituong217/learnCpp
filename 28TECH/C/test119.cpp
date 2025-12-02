#include <stdio.h>
#define ll long long

ll be(ll a[], ll n){
	ll min=1e9;
	for (ll i=0; i<n; i++){
		if (a[i]<min){
			min = a[i];
		}
	}
	return min;
}

ll kt(ll a[], ll n, ll min){
	ll kt=0;
	for (ll i = min; i>=0; i--){
		kt=0;
		for (ll j=0; j<n; j++){
			if (a[j]%min==0) kt++;
		}
		if (kt==n) return i;
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	ll min = be(a, n);
	printf("%lld", kt(a, n, min));
	return 0;
}
