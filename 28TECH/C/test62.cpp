#include <stdio.h>
#include <math.h>

int sphenic(long long n){
	if (n<2) return 0;
	int cnt=0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0){
			cnt++;
			int du=0;
			while(n%i==0){
				du++;
				n/=i;
			}
			if (du>1) return 0;
		}
	}
	if (n!=1) cnt++;
	if (cnt==3){
		return 1;
	}
	else return 0;
}

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%d", sphenic(n));
	return 0;
}
