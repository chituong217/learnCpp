#include <stdio.h>
#define ll long long

void inFibo(ll n){
	ll F1=1%10;
	if (n==1) printf("%lld\n", F1);
	ll F2=2%10;
	if (n==2) printf("%lld\n", F2);
	ll F;
	for (int i=3; i<=n; i++){
		F=((F1%10) + (F2%10))%10;
		if (n==i){
			printf("%lld\n", F);
			return;
		}
		F1=F2;
		F2=F;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while (t){
		ll n;
		scanf("%lld", &n);
		inFibo(n%60);
		--t;
	}
	return 0;
}
