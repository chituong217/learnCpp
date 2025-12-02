#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n;
	scanf("%d", &n);
	while (getchar() != '\n');
	char c[1000];
	printf("Nhap vao xau ki tu:");
	fgets(c, 1000, stdin);
	printf("Xau ki tu vua duoc nhap la: %s", c);
	return 0;
}
