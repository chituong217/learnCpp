#include <stdio.h>
#include <math.h>
#define ll long long 

int stn(int n){
	int res=n;
	int lat =0;
	while (n){
		lat = lat*10 + n%10;
		n/=10;
	}
	return res == lat;
}

int sodep(int n){
	if (stn(n)==0) return 0;
	int cnt=0;
	for (int i=2; i<=sqrt(n); i++){
		if(n%i==0){
			cnt++;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if (n!=1) cnt++;
	if (cnt>=3) return 1;
	else return 0;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int kt=0;
	for (int i=a; i<=b; i++){
		if (sodep(i)==1){
			printf("%d ", i);
			++kt;
		}
	}
	if (kt==0) printf("-1");
	return 0;
}
