#include <stdio.h>

void hello(char *name);

int main(){
    char *name ;

    printf("isminiz : ");
    scanf("%s",name);


    for(int i = 0 ; i<10 ; i++){
        hello(name);
    }
    return 0;
}

void hello(char *name){
    printf("Adınız: %s\n",name);
}