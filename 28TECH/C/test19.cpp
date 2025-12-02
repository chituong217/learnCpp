#include <stdio.h>
int main(){
	int x, y, z, t;
	char c= ' ';
	scanf("%d %d %d %d", &x, &y ,&z, &t);
	printf("%d  %d  %d  %d\n", x, y, z, t);
	printf("%c\n",c);
	printf("%d--%d--%d--%d\n", y, z, x, t);
	printf("%c\n",c);
	printf("%lld,%lld,%lld,%lld\n", (long long)x*2, (long long)y*3, (long long)z*4, (long long)t*5);
	printf("%c\n",c);
	printf("KET THUC !!\n");
	return 0;
}
