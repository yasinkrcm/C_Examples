#include <stdio.h>

long long fact(long long n);

int main(){
    long long n , result ;

    printf("Faktöriyeli alınması istenen sayı  : ");
    scanf("%lld",&n);
    
    if(n < 0 ) printf("girilen değer 0'dan büyük değil lütfen pozitif sayılar giriniz!\n");
    
    else{
        result = fact(n);
        printf("\n%lld sayısının faktöriyeli : %lld\n\n",n,result);
    }
    return 0;    
}

long long fact(long long n){
    if(n == 0 || n == 1) return 1;
    else return n*fact(n-1);
}