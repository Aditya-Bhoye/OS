#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,head,total=0;
    int req[50];
    printf("Enter number of requests : ");
    scanf("%d",&n);
    if(n<=0){
        printf("No requests \n");
        return 0;
    }
    printf("Enter requests sequence : ");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter head movement : ");
    scanf("%d",&head);
    printf("CURRENT\tHEAD MOVEMENT\n");
    printf("%d\t%d\n",head,0);
    for(i=0;i<n;i++){
        int diff=abs(head-req[i]);
        printf("%d\t%d\n",req[i],diff);
        total+=diff;
        head=req[i];
    }
    printf("\nTotal Seak Time : %d\n",total);
}
