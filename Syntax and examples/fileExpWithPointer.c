#include <stdio.h>

int main(){
    FILE *file = fopen("datas/Examples67.txt","w");

    if (file==NULL){
        printf("Dosya açılamadı.\n");
        return 1;
    }
    
    char line[100];

    while (fgets(line,sizeof(line),file)!=NULL)
        printf("Okunan satır : %s",line);
    fclose(file);
    return 0;
    
}