#include <stdio.h>
#include <math.h>
#define ll long long

int ucln(int a, int b){
	while(b){
		if (a==1 && b==1) return 0;
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int bcnn(int a, int b, int c){
	int u1 = ucln(a,b);
	if (u1==0) return 0;
	int u = ucln(u1,c);
	if(u==0) return 0;
	int bcnn1 = a*b / (u1);
	int bcnn = bcnn1*c/ u;
	return bcnn;
}

ll ham(int x,int y,int z,int n){
	if (bcnn(x,y,z)==0) return -1;
	for (ll i= pow(10, n-1); i< pow(10, n); i++){
		if (i%bcnn(x,y,z)==0){
			return i;
		}
	}
	return -1;
}

int main(){
	int x, y, z, n;
	scanf("%d %d %d %d", &x, &y, &z, &n);
	printf("%lld", ham(x,y,z,n));
	return 0;
}
