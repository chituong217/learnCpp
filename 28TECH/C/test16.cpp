#include <stdio.h>
#include <math.h>
int main (){
	int a, b;
	printf ("Nhap gia tri cua a va b:");
	scanf ("%d %d", &a, &b);
	printf ("Tri tuyet doi cua a la :%d\n", (int)abs(a));
	printf ("Can bac hai cua a la :%.2lf\n", sqrt(a));
	printf ("Gia tri cua a luy thua b la :%d\n", (int)pow(a,b));
	printf ("So nho hon trong a va b la :%d\n", (int)fmin(a,b));
	printf ("So lon hon trong a va b la :%d\n", (int)fmax (a,b));
	return 0;
}
