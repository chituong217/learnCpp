#include <stdio.h>
int main(){
	int T;

	scanf("%d", &T);
	for (int i=1; i<=T; i++){
		int n;
		scanf("%d", &n);
		if (n%2==0){
			printf("EVEN\n");
		}
		else printf("ODD\n");
	}
}
