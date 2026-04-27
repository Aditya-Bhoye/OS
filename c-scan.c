#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,total=0,head,size;
    int req[50],temp;
    printf("Enter number of request : ");
    scanf("%d",&n);
    printf("Enter requests sequence :");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter disk size : ");
    scanf("%d",&size);
    printf("Enter current head : ");
    scanf("%d",&head);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    int start=head;
    printf("----------------------------\n");
    printf("Current\t| Head Movement\n");
    printf("%d\t| 0\n",head);
    for(i=0;i<n;i++){
        if(req[i]>=start){
            int diff=abs(head-req[i]);
            printf("%d\t| %d\n",req[i],diff);
            total+=diff;
            head=req[i];
        }
    }
    if(head!=size-1){
        int diff=abs(head-(size-1));
        printf("%d\t| %d\n",size-1,diff);
        total+=diff;
        head=size-1;
    }
    int diff=abs(head-0);
    printf("0\t| %d\n",diff);
    total+=diff;
    head=0;diff=0;
    for(i=0;i<n;i++){
        if(req[i<start]){
            int diff=abs(head-req[i]);
            printf("%d\t| %d\n",req[i],diff);
            total+=diff;
            head=req[i];
        }
    }
    printf("\n-------------------------\n");
    printf("SEEK LENGTH :%d\n",total);
}
