#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,head,total=0,req[20];
    printf("Enter number of requests : ");
    scanf("%d",&n);
    printf("Enter request sequence : ");
    for(i=0;i<n;i++){scanf("%d",&req[i]);}
    printf("Enter current head movement : ");
    scanf("%d",&head);
    printf("Current\t| Head Movement\n");
    printf("%d\t| 0\n",head);
    for(i=0;i<n;i++){
        int diff=abs(head-req[i]);
        printf("%d\t| %d\n",req[i],diff);
        head=req[i];
        total+=diff;
    }
    printf("Total seak length : %d\n",total);
}
