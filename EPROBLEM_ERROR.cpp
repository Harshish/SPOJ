#include <bits/stdc++.h>
typedef unsigned long long ULL;
void pN(ULL x){if(x<1){return;}else if(x==1){printf("2(0)");}else if(x==2){printf("2");}else if(x==3){printf("2+2(0)");}else{int n=log2(x);printf("2(");pN(n);printf(")");ULL num=x-pow(2,n);if(num>0){printf("+");pN(num);}}}int main(){ULL x;while (scanf("%llu", &x)!=EOF){printf("%llu=",x);pN(x);}return 0;}