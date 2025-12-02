#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char c[500], ans[500] = "";
	cin.get(c, 500, '\n');
	char *token = strtok(c, " ");
	while (token != NULL){
		strcat(ans, token);
		strcat(ans, " ");
		token = strtok(NULL, " ");
	}
	if (ans[strlen(ans)] == ' '){
		ans[strlen(ans)] = '\n';
	}
	cout << ans;
	return 0;
}
