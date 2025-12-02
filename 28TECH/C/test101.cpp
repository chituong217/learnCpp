#include <stdio.h>
#define ll long long

int maxx(ll n){
	if (n<10) return n;
	if (n%10 >= maxx(n/10)) return n%10;
	else return maxx(n/10);
}

int minn (ll n){
	if (n<10) return n;
	if (n%10 <= minn(n/10)) return n%10;
	else return minn(n/10);
}

int main(){
	ll n;
	scanf("%lld", &n);
	printf("%d %d", maxx(n), minn(n));
	return 0;
}
