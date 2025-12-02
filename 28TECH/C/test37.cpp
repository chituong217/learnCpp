#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (int i=n; i>=1; i--){
		for (int j=i; j>=1; j--){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (int i=1; i<=n; i++){
		for (int k=n-i; k>=1; k--){
			printf(" ");
		}
		
		for (int j=1; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	for (int i=n; i>=1; i--){
		for (int k=n-i; k>=1; k--){
			printf(" ");
		}
		
		for (int j=i; j>=1; j--){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");


	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			if (i>2 && i<n){
				if (j==1 || j==i){
					printf("*");
				} else printf(" ");
			} else printf("*");
		}
		printf("\n");
	}
	printf("\n");
	

}
