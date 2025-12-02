#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(){
	int n; scanf("%d", &n);
	getchar();
	while(n--){
		char c[5000];
		fgets(c, 5000, stdin);
		c[strlen(c)-1] = '\0';
		for (int i=0; i<strlen(c); i++){
			c[i] = tolower(c[i]);
		}
		char a[1000][20] = {0};
		int n=0;
		char *token = strtok(c, " ");
		while (token != NULL){
			strcpy(a[n++], token);
			token = strtok(NULL, " ");
		}
		
		token = strtok(a[n-1], "/");
		while(token!= NULL){
			int so = atoi(token);
			printf("%d", so);
			token = strtok(NULL, "/");
		}
		printf("\n");
		
	}
}
