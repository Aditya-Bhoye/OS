#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,head,total=0,size;
    int req[20],temp;
    printf("Enter number of request : ");
    scanf("%d",&n);
    printf("Enter request sequence : ");
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
    printf("\n----------------------------\n");
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
    for(i=n-1;i>=0;i--){
        if(req[i]<start){
            int diff=abs(head-req[i]);
            printf("%d\t| %d\n",req[i],diff);
            total+=diff;
            head=req[i];
        }
    }
    printf("\n----------------------------\n");
    printf("SEEK LENGTH :%d\n",total);
}
