#include <stdio.h>
#include <math.h>

int tsntk(int n, int k){
	int m=0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0){
			while(n%i==0){
				m++;
				if (m==k) {
					return i;
				}
				n/=i;
			}
		}
	}
	if (n!=1) m++;
	if (m==k) {
		return n;
	}
	return -1;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf ("%d", tsntk(n, k));
	return 0;
}
