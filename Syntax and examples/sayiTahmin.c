#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int secret , guess;
    srand(time(0));
    secret = rand() % 100 + 1;

    printf("1 ile 100 arasındaki bir sayıyı tahmin ediniz:");


    do{
        scanf("%d",&guess);
            if (guess>secret)  printf("Daha küçük bir sayı girin  :");
            else if (guess<secret) printf("Daha büyük bir sayı giriniz :");
            else printf("Tebrikler sayı doğru \n");

    }while(guess != secret);
            
}