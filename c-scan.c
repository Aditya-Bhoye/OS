#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,head,total=0,size,dir;
    int req[50],temp;
    printf("Enter number of requests : ");
    scanf("%d",&n);
    if(n<=0){printf("No requests\n");return 0;}
    printf("Enter requests sequence : ");
    for(i=0;i<n;i++){scanf("%d",&req[i]);}
    printf("Enter current head : ");
    scanf("%d",&head);
    printf("Enter disk size : ");
    scanf("%d",&size);
    printf("Enter direction 1=right 0=left : ");
    scanf("%d",&dir);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                temp=req[j];req[j]=req[j+1];req[j+1]=temp;
            }
        }
    }
    int start=head;
    printf("Current\tHead Movement\n");
    printf("%d\t%d\n",head,0);
    if(dir==1){
        for(i=0;i<n;i++){
            if(req[i]>=start){
                int diff=abs(head-req[i]);
                printf("%d\t%d\n",req[i],diff);
                total+=diff;
                head=req[i];
            }
        }
        if(head!=size-1){
            int diff=abs(head-(size-1));
            printf("%d\t%d\n",size-1,diff);
            total+=diff;
            head=size-1;
        }
        int diff=abs(head-0);
        printf("0\t%d\n",diff);
        total+=diff;
        head=0;
        for(i=0;i<n;i++){
            if(req[i]<start){
                int diff=abs(head-req[i]);
                printf("%d\t%d\n",req[i],diff);
                total+=diff;
                head=req[i];
            }
        }
    }else{
        for(i=n-1;i>=0;i--){
            if(req[i]<=start){
                int diff=abs(head-req[i]);
                printf("%d\t%d\n",req[i],diff);
                total+=diff;
                head=req[i];
            }
        }
        if(head!=0){
            int diff=abs(head-0);
            printf("%d\t%d\n",0,diff);
            total+=diff;
            head=0;
        }
        int diff=abs(head-(size-1));
        printf("%d\t%d\n",size-1,diff);
        total+=diff;
        head=size-1;
        for(i=n-1;i>=0;i--){
            if(req[i]>start){
                int diff=abs(head-req[i]);
                printf("%d\t%d\n",req[i],diff);
                total+=diff;
                head=req[i];
            }
        }
    }
    printf("\nTotal Seek Length : %d\n",total);
}
