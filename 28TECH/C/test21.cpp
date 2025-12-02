#include <stdio.h>
#include <math.h>
int main(){
	double f;
	scanf("%lf", &f);
	printf("%d\n", (int)f);
	printf("%.2lf", f - floor(f));
}
