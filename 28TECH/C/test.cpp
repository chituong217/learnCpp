#include <stdio.h>
#include <math.h>
#define ll long long

ll N[10000001];

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

void mang(ll b, ll a, ll A[]){
	for (ll i=0; i<a; i++){
		N[i]= b + A[i];
	}
}


int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll A[a], B[b];
	for (ll i=0; i<a; i++){
		scanf("%lld", &A[i]);
	}
	for (ll i=0; i<b; i++){
		scanf("%lld", &B[i]);
	}
	for (ll i=0; i<b; i++){
		mang(B[i], a, A);
		printf("%lld\n", kt(N, a));
	}
	return 0;
}
