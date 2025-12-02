#include <stdio.h>

int main(){
	int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i=0; i<(1<<3); i++){
		printf("{");
		for (int j=0; j<3; j++){
			if (i & (1<<j)){
				printf("%d ", a[j]);
			}
		}
		printf("}\n");
	}
	return 0;
}
