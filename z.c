#include <stdio.h>
#include <unistd.h>
int main(){
    int p=fork();
    if(p==0){
        printf("Child PID=%d and its parent PID=%d\n",getpid(),getppid());
        for(char ch='a';ch<='z';ch++){
            printf("%c\n",ch);
            sleep(1);
        }
    }else{
        printf("Parent PID=%d and its parent PID=%d\n",getpid(),getppid());
        for(char ch='A';ch<='Z';ch++){
            printf("\t%c\n",ch);
            sleep(2);
        }
    }
}