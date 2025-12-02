#include <stdio.h>
#define ll long long

int main(){
	ll n;
	ll cnt=0;
	scanf("%lld", &n);
	while (n>=1000){
		if (n==0) break;
		cnt+= n/1000;
		n= n%1000;
	}
	while (n>=500){
		if (n==0) break;
		cnt+= n/500;
		n= n%500;
	}
	while (n>=200){
		if (n==0) break;
		cnt+= n/200;
		n= n%200;
	}
	while (n>=100){
		if (n==0) break;
		cnt+= n/100;
		n= n%100;
	}
	while (n>=50){
		if (n==0) break;
		cnt+= n/50;
		n= n%50;
	}
	while (n>=20){
		if (n==0) break;
		cnt+= n/20;
		n= n%20;
	}
	while (n>=10){
		if (n==0) break;
		cnt+= n/10;
		n= n%10;
	}
	while (n>=5){
		if (n==0) break;
		cnt+= n/5;
		n= n%5;
	}
	while (n>=2){
		if (n==0) break;
		cnt+= n/2;
		n= n%2;
	}
	while (n>=1){
		if (n==0) break;
		cnt+= n;
		n= 0;
	}
	printf("%lld", cnt);
}
