#include <stdio.h>
#define ll long long

int chan(ll n){
	if (n<10){
		if (n%2==0) return n;
		else return 0;
	}
	else{
		if (n%2==0) return n%10 + chan(n/10);
		else return chan(n/10);
	} 
}

int le(ll n){
	if (n<10){
		if (n%2!=0) return n;
		else return 0;
	}
	else{
		if (n%2!=0) return n%10 + le(n/10);
		else return le(n/10);
	} 
}

int main(){
	ll n;
	scanf("%lld", &n);
	printf("%d\n%d", chan(n), le(n));
	return 0;
}
