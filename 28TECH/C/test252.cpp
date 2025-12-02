#include <stdio.h>
#include <math.h>
typedef struct SoPhuc SoPhuc;

struct SoPhuc{
	int thuc;
	int ao;
};

int main(){
	SoPhuc a, b;
	scanf("%d %d", &a.thuc, &a.ao);
	scanf("%d %d", &b.thuc, &b.ao);
	printf("%d %d\n", a.thuc + b.thuc, a.ao + b.ao);
	printf("%d %d\n", a.thuc - b.thuc, a.ao - b.ao);
	printf("%d %d\n", a.thuc * b.thuc - a.ao * b.ao, a.thuc * b.ao + a.ao * b.thuc);
	return 0;
}
