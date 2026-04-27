#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,head,total=0,count=0,req[50],visited[50]={0};
    printf("Enter number of request you want : ");
    scanf("%d",&n);
    printf("Enter request sequence : ");
    for(i=0;i<n;i++){scanf("%d",&req[i]);}
    printf("Enter current head movement : ");
    scanf("%d",&head);
    printf("Current\t| Head movement\n");
    printf("%d\t| 0\n",head);
    while(count<n){
        int min=9999,idx=-1;
        for(i=0;i<n;i++){
            if(!visited[i]){
                int diff=abs(head-req[i]);
                if(diff<min){
                    min=diff;
                    idx=i;
                }
            }
        }
        if(idx==-1) break;
        visited[idx]=1;
        int diff=abs(head-req[idx]);
        printf("%d\t| %d\n",req[idx],diff);
        total+=diff;
        head=req[idx];
        count++;
    }
    printf("Seak length %d\n",total);
}
