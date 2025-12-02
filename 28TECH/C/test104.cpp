#include <stdio.h>
#define ll long long

int kt(ll n){
	if(n<10){
		if (n%2==0) return 1;
		else return 0;
	}
	else {
		if (n%2!=0) return 0;
		else  return kt(n/10);
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	if (kt(n)==1) printf("YES");
	else printf("NO");
	return 0;
}
