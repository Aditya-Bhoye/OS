#include<stdio.h>
int main(){
    int n,i,time=0,completed=0,k=0;
    int at[20],bt[20],ct[20],tat[20],wt[20],pr[20],done[20],exec[20];
    printf("Enter number of process you want : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter arrival time for process P%d : ",i);
        scanf("%d",&at[i]);
        printf("Enter brust time for process P%d : ",i);
        scanf("%d",&bt[i]);
        printf("Enter priority for process P%d : ",i);
        scanf("%d",&pr[i]);
        done[i]=0;
    }
    while(completed<n){
        int idx=-1;
        for(i=0;i<n;i++){
            if(!done[i] && at[i]<=time){
                if(idx==-1 || pr[i]<pr[idx] || (pr[i]==pr[idx] && at[i]<at[idx]) || (pr[i]==pr[idx] && at[i]==at[idx] && bt[i]<bt[idx])){
                    idx=i;
                }
            }
        }
        if(idx==-1){ time++; continue;}
        exec[k++]=idx;
        time+=bt[idx];
        ct[idx]=time;
        done[idx]=1;
        completed++;
    }
    float total_tat=0,total_wt=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_tat+=tat[i];
        total_wt+=wt[i];
    }
    printf("Process\tAT\tBT\tCT\tPR\tTAT\tWT\n");
    for(i=0;i<n;i++){
        int x=exec[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",x,at[x],bt[x],ct[x],pr[x],tat[x],wt[x]);
    }
    time=0;
    printf("\n--------------------------------------\n");
    printf("|");
    for(i=0;i<n;i++){
        int x=exec[i];
        if(time<at[x]){
            time=at[i];
            printf(" IDLE | ");
        }
        time+=bt[x];
        printf(" P%d |",x);
    }
    printf("\n--------------------------------------\n");
    time=0;
    printf("0");
    for(i=0;i<n;i++){
        int x=exec[i];
        if(time<at[x]){
            time=at[i];
            printf("    %d ",time);
        }
        time+=bt[x];
        printf("    %d",time);
    }
    printf("\nAVG TAT : %.2f",total_tat/n);
    printf("\nAVG WT : %.2f\n",total_wt/n);
}
