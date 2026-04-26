#include<stdio.h>
int main(){
    int n,i,j,temp,time=0;
    int at[20],bt[20],ct[20],tat[20],wt[20],order[20]; 
    printf("Enter number of process you want : ");
    scanf("%d",&n);
    if(n<=0){printf("No requests");return 0;}
    for(i=0;i<n;i++){
        printf("Enter arrival time for process P%d : ",i);
        scanf("%d",&at[i]);
        printf("Enter brust time for process P%d : ",i);
        scanf("%d",&bt[i]);
        order[i]=i;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j] ; at[j]=at[j+1] ; at[j+1]=temp;
                temp=bt[j] ; bt[j]=bt[j+1] ; bt[j+1]=temp;
                temp=order[j] ; order[j]=order[j+1] ; order[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(time<at[i]) time=at[i];
        time+=bt[i];
        ct[i]=time;
    }
    float total_tat=0,total_wt=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_tat+=tat[i];
        total_wt+=wt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        int x=order[i]; 
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",x,at[x],bt[x],ct[x],tat[x],wt[x]);
    }
    printf("\n-------------------\n");
    printf("|");
    time=0;
    for(i=0;i<n;i++){
        if(time<at[i]){
            printf(" IDLE |");
            time=at[i];
        }
        time+=bt[i];
        printf(" P%d |",order[i]); 
    }
    printf("\n-------------------\n");
    time=0;
    for(i=0;i<n;i++){
        if(time<at[i]){
            printf("%d",time);
            time=at[i];
            printf("    %d",time);
        }
        time+=bt[i];
        printf("    %d",time);
    }
    printf("\nAVG TAT %.2f",total_tat/n);
    printf("\nAVG WT %.2f\n",total_wt/n);
}
