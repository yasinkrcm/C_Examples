#include <stdio.h>

int toplam(int a , int b);

int toplam(int a , int b){
    return a+b ;
}

int main(){
    int a,b;
    printf("Birinci sayıyı giriniz :"); 
    scanf("%d",&a); 
    printf("İkinci sayıyı giriniz : "); 
    scanf("%d",&b);
    printf("Toplam : %d\n",toplam(a,b));
   return 0;
}