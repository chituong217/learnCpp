long long ltnp(int a, int b){
    long long res = 1;
    while (b != 0){
        if (b % 2 == 1){
            res *= a;
        }
        a*=a;
        b/=2;
    }
    return res;
}