#include <stdio.h>
#define ll long long

int kt(ll a[], ll n){
	for (ll i=0; i<= n/2; i++){
		if ( a[i] != a[n-1-i]) return 0;
	}
	return 1;
}


int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	if (kt(a, n)==1) printf("YES");
	else printf("NO");
	return 0;
}
