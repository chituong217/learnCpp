#include <stdio.h>
#define ll long long 

int daucuoi(ll n){
	int cuoi =n%10;
	while (n){
		n/=10;
		if (n<10){
			break;
		}
	}
	if ((n*2==cuoi) || (cuoi*2==n)){
		return 1;
	}
	else return 0;
}

int giua(ll n){
	ll giua =0;
	n/=10;
	ll cnt=1;
	while(n>=10){
		giua = (n%10)*cnt + giua;
		n/=10;
		cnt*=10;
	}
	ll res = giua;
	ll lat =0;
	while(giua){
		lat = lat*10 + giua%10;
		giua/=10;
	}
	return res == lat;
}

int main(){
	ll n;
	scanf("%lld", &n);
	if ((daucuoi(n)==1) && giua(n)==1){
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}


