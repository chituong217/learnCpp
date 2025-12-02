#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char c[100005];
	fgets(c, 100005, stdin);
	c[strlen(c)-1] = '\0';
	int res = 0, cnt = 1;
	int bestS = 0, bestE = 0;
	int start = 0, end = 0;
	for (int i=1; i < strlen(c); i++){
		if ((i != strlen(c)-1) && c[i] != c[i-1]){
			cnt++;
			end++;
		}
		else{
			if (i == strlen(c)-1 && c[i] != c[i-1]){
				cnt++;
				end++;
			}
			if (res < cnt){
				res = cnt;
				bestS = start;
				bestE = end;
				start = i;
				end = i;
				cnt = 1;
			}
			else if (res == cnt){
				for (int j=0; j < cnt; j++){
					if (c[start+j] < c[bestS+j]){
						break;
					}
					else if (c[start + j] > c[bestS + j]){
						bestS = start;
						bestE = end;
						break;
					}
				}
				start = i;
				end = i;
				cnt = 1;
			}
			else{
				start = i;
				end = i;
				cnt = 1;
			}
		}
	}
	for (int i = bestS; i <= bestE; i++){
		printf("%c", c[i]);
	}
	return 0;
}
