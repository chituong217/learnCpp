#include <stdio.h>
#define ll long long

ll ucln(ll a, ll b){
	if (b==0) return a;
	else return ucln(b,a%b);
}

ll kt(ll a[], ll n){
	ll kt=a[0];
	for (ll i=0; i<n; i++){
		kt = ucln(kt, a[i]);
		if (kt==1) return 1;
	}
	return kt;
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	printf("%lld", kt(a, n));
	return 0;
}
