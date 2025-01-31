#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    pid_t pid;
    pid_t ppid;


    pid = getpid();

    ppid = getppid();


    // printf("Bulunduğum dizin : ");
    // system("pwd")
    // printf("Bulunduğum dizindeki dosyalar : ");
    // system("ls")
 

    printf("Bu süresin PID'si : %d\n",pid);
    printf("Bu süresin PPID'si : %d\n",ppid);
    

    /*  Process Doğruluğu kontrolü
    for (int i = 0 ; i<10000001 ; i++){
        printf("%d",i); 
    }    
    */
    return 0;

}