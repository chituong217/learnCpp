#include <stdio.h>
#include <math.h>

int sohoanhao(int n){
	int test =0;
	for (int i=1; i<= sqrt(n); i++){
		if (n%i==0){
			test+=i;
			if (i!=n/i){
				test += n/i;
			}
		}
	}
	return test - n;
}

int main (){
	int n;
	scanf("%d", &n);
	if (sohoanhao(n)==n){
		printf("1");		
	}
	else printf("0");
	return 0;
}
