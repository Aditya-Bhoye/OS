#include <stdio.h>
int main(){
    int n,i,j,temp;
    int at[20],bt[20],ct[20],tat[20],wt[20],order[20];
    printf("Enter number of process you want :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter arrival time for process P%d : ",i);
        scanf("%d",&at[i]);
        printf("Enter brust time for process P%d : ",i);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j] ; at[j]=at[j+1] ;at[j+1]=temp;
                temp=bt[j] ; bt[j]=bt[j+1] ;bt[j+1]=temp;
                temp=order[j] ;order[j]=order[j+1] ; order[j+1]=temp;
            }
        }
    }
    if(at[0]>0){
        ct[0]=at[0]+bt[0];
    }else{
        ct[0]=bt[0];
    }
    for(i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        }else{
            ct[i]=ct[i-1]+bt[i];
        }
    }
    float total_wt=0,total_tat=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d \t%d \t%d \t%d \t%d \t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Average waiting =%.2f",total_wt/n);
    printf("Average turnaround time =%.2f",total_tat/n);
}