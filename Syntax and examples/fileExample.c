#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define READ_SIZE 256
#define WRITE_SIZE 256
#define NAME_SIZE 100


int main(){
    char filename[NAME_SIZE];
    char sentence[WRITE_SIZE];
    int fd;

    printf("Dosyanın adını girin: ");
    scanf("%s",filename);

    strcat(filename,".txt");

    printf("Kendinizi bir cümle ile açıklayınız.\n");
    // scanf("%s",sentence);
    getchar();
    fgets(sentence,sizeof(sentence),stdin);

    fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0644);

    if(fd == -1){
        perror("Dosya açılırken hata oluştu.");
        return 1;
    }

    ssize_t bytesWrite = write(fd,sentence,strlen(sentence));

    close(fd);

    fd = open(filename,O_RDONLY);

    char buffer[READ_SIZE];

    ssize_t bytesRead = read(fd,buffer,sizeof(buffer)-1);

    buffer[bytesRead] = '\0';

    printf("Verinin tersi : \n");

    for(int i = bytesRead -2  ; i>=0;i--)
        putchar(buffer[i]);
    
    printf("\n");
    close(fd);
    return 0 ;
}
