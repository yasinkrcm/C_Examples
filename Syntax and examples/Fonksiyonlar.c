#include <stdio.h>

char *hello(char *name);

int main(){
    char *name ;

    printf("isminiz : ");
    scanf("%s",name);

    for(int i = 0 ; i<10 ; i++){
        char *result = hello(name);
        printf("%s\n",result);
    }
    return 0;
}

char *hello(char *name){
    return("Adınız: %s",name);
}



