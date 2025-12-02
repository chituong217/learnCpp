#include <stdio.h>
#include <math.h>
#define ll long long

ll ucln(ll a, ll b){
	while(b){
		ll r=a%b;
		a=b;
		b=r;
	}
	return a;
}

ll bcnn(ll a, ll b, ll c){
	ll ab = a*b/ucln(a,b);
	ll bcnn = ab*c/ucln(ab,c);
	return bcnn;
}

ll pow10(int n){
	ll res =1;
	for (int i=0; i<n; i++){
		res*=10;
	}
	return res;
}

ll ham(ll b,int n){
	if (b==0) return -1;
	ll start = pow10(n-1);
	ll end = pow10(n);
	if (start%b==0){
		return start;
	} 
	else start = start + (b- start%b);
	if (start<end) return start;
	return -1;
}

int main(){
	ll x,y,z;
	int n;
	scanf("%lld %lld %lld %d", &x, &y, &z, &n);
	ll b = bcnn (x,y,z);
	printf("%lld", ham(b, n));
	return 0;
}
