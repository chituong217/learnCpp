#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int bia = n/28;
	int vo = bia;
	while (vo>=3){
		vo-=3;
		bia++;
		vo++;
	}
	printf("%d", bia);
	return 0;
}
