#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){
    int i = 0;
    while (i != 100){
        pid_t pid = fork();
        if (pid == -1){
            printf("fork hatası.");
            exit(EXIT_FAILURE);
        }
        if (pid == 0){
            printf("Çocuk süreç başlatılıyor. PID : %d\n", getpid());

            pid_t firefox_pid = fork(); 
            if (firefox_pid == 0){
                char *args[] = {"firefox", NULL};
                system("apt update && apt upgrade");
                execvp("firefox", args);
                perror("Execvp hatası.");
                exit(EXIT_FAILURE);
            } else {
                sleep(001);
                printf("Firefox süreci PID: %d sonlandırılıyor.\n", firefox_pid);
                kill(firefox_pid,SIGKILL);  
                exit(EXIT_SUCCESS);  
            }
        } else {
            printf("Çocuk süreç bekletiliyor PID : %d\n", getpid());
            int status;
            wait(&status);
            printf("Çocuk süreç tamamlandı. Durum : %d\n", WEXITSTATUS(status));
        }
        i++;
    }
    return 0;
}
