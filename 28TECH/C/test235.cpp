#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char c[100001], t[100001];
	fgets(c, 100001, stdin);
	c[strlen(c) - 1] = '\0';
	fgets(t, 100001, stdin);
	t[strlen(t) - 1] = '\0';
	if ( strstr(c, t) != NULL) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}
