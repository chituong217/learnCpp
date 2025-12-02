#include <stdio.h>
#define ll long long

int main(){
	int Fibo[61];
	Fibo[1]=1;
	Fibo[2]=2;
	for (int i=3; i<=60; i++){
		Fibo[i]= (Fibo[i-1]+Fibo[i-2])%10;
	}
	
	int t;
	scanf("%d", &t);
	while (t){
		ll n;
		scanf("%lld", &n);
		int index = n%60;
		if (index==0) index=60;
		printf("%d\n", Fibo[index]);
		--t;
	}
	return 0;
}
