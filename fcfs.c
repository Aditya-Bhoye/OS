#include <stdio.h>
int main(){
    int n,i,j,temp;
    int at[20],bt[20],ct[20],tat[20],wt[20],order[20],exec[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&at[i],&bt[i]);
        order[i]=i;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j]; at[j]=at[j+1]; at[j+1]=temp;
                temp=bt[j]; bt[j]=bt[j+1]; bt[j+1]=temp;
                temp=order[j]; order[j]=order[j+1]; order[j+1]=temp;
            }
        }
    }
    int time=0;
    for(i=0;i<n;i++){
        if(time<at[i]) time=at[i];
        time+=bt[i];
        ct[i]=time;
        exec[i]=i;
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(i=0;i<n;i++){
        int x=exec[i];
        printf("P%d %d %d %d %d %d\n",order[x],at[x],bt[x],ct[x],tat[x],wt[x]);
    }
}
