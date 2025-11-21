#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    double p, q;
    scanf("%lf%lf", &p, &q);
    double x = cbrt(sqrt(pow(p,6)/27 + pow(q,2)/4)- q/2) - cbrt(sqrt(pow(p,6)/27 + pow(q,2)/4) + q/2);
    printf("%lf", x);
}