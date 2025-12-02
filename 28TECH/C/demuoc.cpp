#include <stdio.h>
#include <math.h>

int demuoc(int n){
	long long cnt=0;
	for (int i=1; i<= sqrt(n); i++){
		if (n%i==0){
			cnt++;
			if (i!=n/i){
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", demuoc(n));
	return 0;
}
