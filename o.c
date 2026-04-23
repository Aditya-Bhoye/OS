#include <stdio.h>
#include <unistd.h>
int main(){
    int p=fork();
    if(p==0){
        printf("Child PID=%d its Parent PID=%d\n" ,getpid(),getppid());
        for(char ch='a';ch<='z';ch++){
            printf("CHILD [%c] PARENT IS=%d \n",ch,getppid());
            sleep(2);
        }
    }else{
        printf("Parent PID=%d its Parent PID=%d\n",getpid(),getppid());
        for(char ch='A';ch<='Z';ch++){
            printf("\t%c\n",ch);
            sleep(1);
        }
    }
}