#include <stdio.h>
#include <math.h>
typedef struct PhanSo PhanSo;

int ucln(int a, int b){
	while(b){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

struct PhanSo{
	int tu;
	int mau;
};

void RutGon(PhanSo &a){
	int uc = ucln(a.tu, a.mau);
	a.tu /= uc;
	a.mau /= uc;
}

PhanSo Cong(PhanSo &a, PhanSo &b){
	PhanSo n;
	n.mau = a.mau * b.mau;
	n.tu = a.tu * b.mau + b.tu * a.mau;
	RutGon(n);
	return n;
}

PhanSo Tru(PhanSo &a, PhanSo &b){
	PhanSo n;
	n.mau = a.mau * b.mau;
	n.tu = a.tu * b.mau - b.tu * a.mau;
	RutGon(n);
	if (n.mau < 0){
		n.mau *= -1;
		n.tu *= -1;
	}
	return n;
}

int main(){
	PhanSo a, b;
	scanf("%d %d", &a.tu, &a.mau);
	scanf("%d %d", &b.tu, &b.mau);
	RutGon(a);
	RutGon(b);
	printf("%d/%d\n", a.tu, a.mau);
	printf("%d/%d\n", b.tu, b.mau);
	PhanSo tong = Cong(a,b), hieu = Tru(a,b);
	printf("%d/%d\n", tong.tu, tong.mau);
	printf("%d/%d\n", hieu.tu, hieu.mau);
	return 0;
}
