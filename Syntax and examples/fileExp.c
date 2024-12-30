#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){
    // int fd = open("datas/examples5.txt", O_CREAT | O_RDONLY | O_WRONLY,0666);
    // if(fd == -1){
    //     perror("Error opening file");
    //     return 1;
    // }
    // printf("File opened successfuly with descriptor %d\n",fd);
    
    // struct stat st;
    // fstat(fd,&st);
    // printf("UID : %d , GID : %d \n",st.st_uid,st.st_gid);

    // close(fd);

    char buffer[6];
    int fd = open("datas/examples5.txt",O_RDONLY,0666);
    
    if(fd == -1){
        perror("Error openning file");
        return 1;
    }

    ssize_t bytesRead;
    int i = 1;
    while((bytesRead = read(fd,buffer,sizeof(buffer)-1))>0){
        buffer[bytesRead] = '\0';
        printf("%d. Döngü %s\n",i,buffer);
        
        i++;
    }
    if (bytesRead == -1){
        perror("Error reading file");
        return 1;
    }

    return 0;
}