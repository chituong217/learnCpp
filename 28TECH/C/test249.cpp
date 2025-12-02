#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	char c[100005];
	scanf("%s", c);
	c[strlen(c)] = 'z';
	c[strlen(c)+1] = '\0'; 
	char best[100005] = "0";
	int idx = 0;
	char current[100005] = "";
	for (int i=0; i<strlen(c); i++){
		if (isdigit(c[i])){
			current[idx] = c[i];
			current[idx+1] = '\0';
			idx++;
		}
		else{
			if (idx >0){
				
				char *p = current;
				
				while (*p == '0' && *(p+1) != '\0'){
					p++;
				}
				
				
				if (strlen(best) < strlen(p)){
					strcpy(best, p);
				}
				else if (strlen(best) == strlen(p)){
					if (strcmp(best, p) < 0){
						strcpy(best, p);
					}
				}
				idx = 0;
				current[0] = '\0';
			}
		}
	}
	printf("%s", best);
	return 0;
}
