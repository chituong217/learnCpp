#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	if (n<2){
		printf("-1\n");
	}
	else {
		
		int cnt = n/2;
		printf("%d\n", cnt);
		if (n%2!=0){
			cnt-=1;
		}
		while (cnt){
			--cnt;
			printf("2 ");
		}
		if (n%2!=0){
			printf("3");
		}
	}
	return 0;
}
