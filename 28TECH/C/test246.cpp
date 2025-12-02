#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int m, s;
	scanf("%d %d", &m, &s);
	char min[m] = {0}, max[m] = {0};
	int check1=0, check2=0;
	int res = s;
	for (int i=0; i<m; i++){
		if (res >= 9){
			max[i] = 9;
			res -= 9;
		}
		else{
			max[i] = res;
			res -= res;
		}
	}
	
	if(res > 0){
		check1 = -1;
	}
	
	if (s == 0){
		if(m==1){
			min[0] = 0;
		}
		else{
			check2=-1;
		}
	}
	else{
		min[0] = 1;
		s--;
	}
	
	for (int i = m - 1; i >= 1; i--){
		if (s >= 9){
			min[i] = 9;
			s -= 9;
		}
		else{
			min[i] = s;
			s -= s;
		}
	}
	if (s < 9 && s>=0){
		min[0] += s;
	}
	else{
		check2 =- 1;
	}
	
	if (check2==-1 || check1==-1){
		printf("NOT FOUND");
	}
	else{
		for (int i=0; i<m; i++){
			printf("%d", min[i]);
		}
		printf("\n");
		for (int i=0; i<m; i++){
			printf("%d", max[i]);
		}
	}
	return 0;
}
