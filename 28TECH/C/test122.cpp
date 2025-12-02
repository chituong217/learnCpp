#include <stdio.h>
#define ll long long
#include <math.h>

int snt(ll n){
	if (n<2) return 0;
	for (ll i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int stn(ll n){
	ll stn=0;
	ll res=n;
	while (n){
		stn= stn*10 +n%10;
		n/=10;
	}
	return res == stn;
}

int scp(ll n){
	ll can = sqrt(n);
	if (can*can == n) return 1;
	else return 0;
}

int tongsnt(ll n){
	int tong =0;
	while (n){
		tong += n%10;
		n/=10;
	}
	return snt(tong);
}

void kt(ll a[], ll n){
	int a1=0, a2=0, a3=0, a4=0;
	for (ll i=0; i<n; i++){
		if (snt(a[i])==1) a1++;
		if (stn(a[i])==1) a2++;
		if (scp(a[i])==1) a3++;
		if (tongsnt(a[i])==1) a4++;
	}
	printf("%d\n%d\n%d\n%d\n", a1, a2, a3, a4);
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	kt(a, n);
	return 0;
}
