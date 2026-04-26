#include <stdio.h>
int main(){
    int n,i;
    int at[20],bt[20],pr[20],ct[20],tat[20],wt[20],done[20],exec[20];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        done[i]=0;
    }
    int time=0,completed=0,k=0;
    while(completed<n){
        int idx=-1;
        for(i=0;i<n;i++){
            if(!done[i] && at[i]<=time){
                if(idx==-1 || pr[i]<pr[idx] ||
                  (pr[i]==pr[idx] && at[i]<at[idx]) ||
                  (pr[i]==pr[idx] && at[i]==at[idx] && bt[i]<bt[idx]))
                    idx=i;
            }
        }
        if(idx==-1){ time++; continue; }
        exec[k++]=idx;
        time+=bt[idx];
        ct[idx]=time;
        done[idx]=1;
        completed++;
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(i=0;i<n;i++){
        int x=exec[i];
        printf("P%d %d %d %d %d %d %d\n",x,at[x],bt[x],pr[x],ct[x],tat[x],wt[x]);
    }
}
