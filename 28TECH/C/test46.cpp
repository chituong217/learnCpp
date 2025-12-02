#include <stdio.h>
#include <math.h>
int tonguoc(int n){
	long long tong =0;
	for (int i=1; i<=sqrt(n); i++){
		if (n%i==0){
			tong+=i;
			if (i!=n/i){
				tong+= (n/i);
			}
		}
	}
	return tong;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", tonguoc(n));
}
