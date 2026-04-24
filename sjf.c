#include <stdio.h>
int main(){
    int n,i,j,temp;
    int at[20],bt[20],ct[20],tat[20],wt[20],done[20],order[20],exec_order[20];
    printf("Enter number of process you want : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter arrival time for process P%d : ",i);
        scanf("%d",&at[i]);
        printf("Enter brust time for process P%d : ",i);
        scanf("%d",&bt[i]);
        order[i]=i;
        done[i]=0;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j];    at[j]=at[j+1];    at[j+1]=temp;
                temp=bt[j];    bt[j]=bt[j+1];    bt[j+1]=temp;
                temp=order[j]; order[j]=order[j+1]; order[j+1]=temp;
            }
        }
    }
    int time=0,completed=0,k=0;
    while(completed<n){
        int min_bt=9999,idx=-1;
        for(i=0;i<n;i++){
            if(!done[i] && at[i]<=time && bt[i]<min_bt){
                min_bt=bt[i];
                idx=i;
            }
        }
        if(idx==-1){ time++; continue; }
        exec_order[k++]=idx;
        time+=bt[idx];
        ct[idx]=time;
        done[idx]=1;
        completed++;
    }
    float total_tat=0,total_wt=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        int x=exec_order[i];
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",order[x],at[x],bt[x],ct[x],tat[x],wt[x]);
    }
    printf("\nAVG TAT =%.2f",total_tat/n);
    printf("\nAVG WT =%.2f\n",total_wt/n);
}