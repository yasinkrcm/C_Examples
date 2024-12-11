#include <stdio.h>

int main(){
    int n;
    
    printf("Sayı : ");
    scanf("%d",&n);
    
    if(n % 2 == 0) printf("Girilen %d sayısı çifttir.\n",n);
    else printf("Girilen %d girilen sayısı tektir.\n",n);

    return 0 ;
}