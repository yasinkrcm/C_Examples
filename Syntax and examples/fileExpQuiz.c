#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define READSIZE 256
#define WRITESIZE 256
#define FILENAMESIZE 100

int main(){
    char filename[FILENAMESIZE];
    char sentence[WRITESIZE];
    int fd;

    printf("Dosya adı: ");
    scanf("%s",filename);

    strcat(filename,".txt");

    printf("Kendinizi bir cümle ile açıklayınız : ");
    getchar();
    fgets(sentence,sizeof(sentence),stdin);


    fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0644);

    if(fd == -1){
        perror("Dosya açmada hata oluştu");
        return 1;
    }


    ssize_t bytesWrite = write(fd,sentence,strlen(sentence));

    if(bytesWrite == -1){
        perror("Dosyaya yazmada bir hata oluştu.");
        close(fd);
        return 1;
    }

    if (close(fd)==-1){
        perror("Dosya kapanma başarısız.");
        return  1;
    }


    fd = open(filename,O_RDONLY);
    
    if(fd == -1){
        perror("Dosya açmada hata oluştu");
        return 1;
    }

    char buffer[READSIZE];

    ssize_t bytesRead = read(fd,buffer,sizeof(buffer)-1);
    
    if(bytesRead == -1){
        perror("Dosyaya yazmada bir hata oluştu.");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0';

    printf("Dosyadaki verinin tersi : ");
    for(int i = bytesRead - 2 ; i>=0 ; i--)
        printf("%c",buffer[i]);
    printf("\n");

    return 0 ;

}