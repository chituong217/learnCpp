#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	if (n<5){
		printf("%d", n);
	}
	else if (n>=5 && n<10){
		printf("%d", n/5 + (n%5)/1);
	}
	else if (n>=10 && n<20){
		if ((n%10)>=5){
			printf("%d", n/10 + (n/10)/5 + (n/10)%5);
		}
		else if ((n%10) <5){
			printf("%d", n/10 + n%10);
		}
	}
	else if (n>=20 && n<100){
		int du = n%20;
		if (du<5){
			printf("%d", n/20 + du);
		}
		else if (du>=5 && du<10){
			printf("%d", n/20 + du/5 + du%5);
		}
		else if (du>=10 && du<20){
			printf("%d", n/20 + du/10 + (du%10)/5 + (du%10)%5);
		}
	}
	else if (n>100){
		int du = n%100;
		if (du<5){
			printf("%d", n/100 + du);
		}
		else if (du>=5 && du<10){
			printf("%d", n/100 + du/5 + du%5);
		}
		else if (du>=10 && du<20){
			printf("%d", n/100 + du/10 + (du%10)/5 + (du%10)%5);
		}
		else if (du>=20 && du<100){
			printf("%d", n/100 + du/20 + (du%20)/10 + ((du%20)%10)/5 + ((du%20)%10)%5);
		}
	}
}
