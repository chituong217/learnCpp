#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char S[1001], F[101], R[101];
    char result[2001];
    cout << "Enter a sentence = ";
    cin.getline(S, 1001);
    cout << "Enter find word = ";
    cin.getline(F, 101);
    cout << "Enter replacing word = ";
    cin.getline(R, 101);

    result[0] = '\0';
    char *pos = S;
    char *found = NULL;
    int lenF = strlen(F);

    while ((found = strstr(pos, F)) != NULL){
        int len_truoc = found - pos;
        strncat(result, pos, len_truoc);
        strcat(result, R);
        pos = found + lenF;
    }

    strcat(result, pos);

    cout << result << endl;

    return 0;
}