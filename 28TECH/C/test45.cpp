#include <stdio.h>

#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORd(i, a, b) for(int i=(a); i>=(b); i--)

int main(){
	FOR (i, 1, 10){
		printf("%d", i);
	}
}
