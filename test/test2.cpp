#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char c[1000];
    printf("Hay nhap xau ki tu vao: ");
    fgets(c, 1000, stdin);
    printf("Xau ki tu da duoc nhap la: %s", c);
    return 0;
}