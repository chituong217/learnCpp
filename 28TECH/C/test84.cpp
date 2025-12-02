#include <stdio.h>
#include <math.h>
#define ll long long

int snt(int n){
	for (int i=2; i<=sqrt(n);i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int tong(int n){
	int tong=0;
	while(n){
		tong+=n%10;
		n/=10;
	}
	return tong;
}

int ktFibo(ll n){
	if (n==0 || n==1) {
		return 1;
	}
	ll Fibo1=0;
	ll Fibo2=1;
	ll Fibo;
	for (int i=2; i<=92; i++){
		Fibo= Fibo1 + Fibo2;
		if (n==Fibo) {
			return 1;
		}
		Fibo1= Fibo2;
		Fibo2= Fibo;
	}
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=2; i<=n; i++){
		if ((snt(i)==1) && (ktFibo(tong(i)))==1){
			printf("%d ", i);
		}
	}
	return 0;
}

