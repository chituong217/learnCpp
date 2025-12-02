#include <stdio.h>
#include <math.h>

int sodep(int n){
	if (n<2) return 0;
	for (int i=2; i<=sqrt(n); i++){
		int sodep=0;
		if (n%i==0){
			while(n%i==0){
				++sodep;
				n/=i;
				}
				if (sodep<2) return 0;
			}
		}
	if (n!=1) {
		return 0;
	}
	else return 1;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i=a; i<=b; i++){
		if (sodep(i)==1) printf("%d ", i);
	}
	return 0;
}
