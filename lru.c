#include<stdio.h>
int main(){
    int n,f,i,j,fault=0,hit=0,clock=0;
    int pages[50],frames[10],l_time[10];
    printf("Enter number of pages you want : ");
    scanf("%d",&n);
    printf("Enter number of frames you want : ");
    scanf("%d",&f);
    printf("Enter page reference string : ");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<f;i++){
        frames[i]=-1;
        l_time[i]=-1;
    }
    printf("Page\t");
    for(i=0;i<f;i++){
        printf("F%d\t",i);
    }
    printf("Status\n");
    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<f;j++){
            if(frames[j]==pages[i]){
                found=1;
                l_time[j]=clock++;
                break;
            }
        }
        if(!found){
            int pos=-1;
            for(j=0;j<f;j++){
                if(frames[j]==-1){
                    pos=j;
                    break;
                }
            }
            if(pos==-1){
                pos=0;
                for(j=1;j<f;j++){
                    if(l_time[j]<l_time[pos]){
                        pos=j;
                    }
                }
            }
            frames[pos]=pages[i];
            l_time[pos]=clock++;
            fault++;
            printf("%d\t",pages[i]);
            for(j=0;j<f;j++){
                if(frames[j]==-1) printf("-\t");
                else printf("%d\t",frames[j]);
            }
            printf("Fault\n");
        }else{
            hit++;
            printf("%d\t",pages[i]);
            for(j=0;j<f;j++){
                if(frames[j]==-1) printf("-\t");
                else printf("%d\t",frames[j]);
            }
            printf("Hit\n"); 
        }
    }
    printf("Total Fault %d\n",fault);
    printf("Total Hit %d \n",hit);
}
