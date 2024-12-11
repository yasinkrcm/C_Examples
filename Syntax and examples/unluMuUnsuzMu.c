#include <stdio.h>

int main(){

    char c ;

    printf("Lütfen bir harf girin : ");
    scanf("%c",&c);

    char sesliHarfler[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o',  'u'};

    int n = sizeof(sesliHarfler)/sizeof(sesliHarfler[0]);

    for (int i = 0; i < 15 ; i++){
        if(sesliHarfler[i] == c){
            printf("Girilen %c harfi sesli harftir.\n",c);
            break;
        }else{
            printf("Girilen %c harfi sessiz harftir.\n",c);
            break;
        }
    }
}