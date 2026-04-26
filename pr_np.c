#include<stdio.h>
int main(){
    int n,i,j,temp;
    int at[20],bt[20],ct[20],tat[20],wt[20],pr[20],done[20],order[20];
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
    int time=0,completed=0,k=0;
    while(completed<n){
        int min_pr=9999,idx=-1;
        for(i=0;i<n;i++){
            if(!done[i] && at[i]<=time && (pr[i]<min_pr || (pr[i]==min_pr && at[i]<at[idx]))){
                min_pr=pr[i];
                idx=i;
            }
        }
        if(idx==-1){ time++; continue ;}
        order[k++]=idx;
        time+=bt[idx];
        ct[idx]=time;
        done[idx]=1;
        completed++;
    }
    float total_wt=0,total_tat=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT");
    for(i=0;i<n;i++){
        int x=order[i];
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",x,at[x],bt[x],pr[x],ct[x],tat[x],wt[x]);
    }
    printf("\nAVG TAT = %.2f",total_tat/n);
    printf("\nAVG WT = %.2f\n",total_wt/n);
}