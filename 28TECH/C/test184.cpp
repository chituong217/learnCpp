#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int value = 0, cnt = 1;
	while (n){
		if (n%10 == 1){
			value += cnt;
		}
		cnt*=2;
		n/=10;
	}
	printf("%d", value);
	return 0;
}
