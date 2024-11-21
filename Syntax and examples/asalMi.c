#include <stdbool.h>
#include <stdio.h>


int main(){
    bool asalMi = 1;
    int n ;
    
    printf("Sayı : ");
    scanf("%d",&n);

    if (n == 1)
        asalMi = 0;

    for (int i = 2; i <= n / 2; i++)
        if(n % i == 0){
            asalMi = 0;
            break;
        }
    
    if (asalMi)
        printf("%d sayısı asaldır .\n\n",n);
    else
        printf("%d sayısı asal değildir.\n\n",n);

    
    


    return 0 ;
}
