#include<stdio.h>
int main(){
    int n,i,j,temp;
    int at[20],bt[20],ct[20],tat[20],wt[20],rem[20],done[20],order[i];
    printf("Enter number of process you want : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter arrival time for process P%d : ",i);
        scanf("%d",&at[i]);
        printf("Enter brust time for process P%d : ",i);
        scanf("%d",&bt[i]);
        order[i]=i;
        done[i]=0;
        rem[i]=bt[i];
    }
    int time=0,completed=0;
    while(completed<n){
        int min_rem=9999,idx=-1;
        for(i=0;i<n;i++){
            if(!done[i] && at[i]<=time && bt[i]<min_rem){
                min_rem=rem[i];
                idx=i;
            }
        }
        if(idx==-1){ time++ ; continue ;}
        rem[idx]--;
        time++;
        if(rem[idx]==0){
            ct[idx]=time;
            done[idx]=1;
            completed++;
        }
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
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",order[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAVG TAT =%.2f",total_tat/n);
    printf("\nAVG WT =%.2f\n",total_wt/n);
}