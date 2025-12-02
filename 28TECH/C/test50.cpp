#include <stdio.h>
#include <algorithm>
#include <math.h>

int dem(long long n){
	int dem=0;
	while (n){
		dem++;
		n/=10;
	}
	return dem;
}


int stn(long long n){
	int cnt=dem(n)-1;
	long long stn=0;
	while (n){
		stn+= (n%10)*pow(10,cnt);
		n/=10;
		cnt--;
	}
	return stn;
}

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%lld", stn(n));
	return 0;
}
