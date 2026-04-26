#include <stdio.h>
int main(){
    int n,i;
    int at[20],bt[20],pr[20],ct[20],tat[20],wt[20],rem[20],exec[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rem[i]=bt[i];
    }
    int time=0,completed=0,k=0;
    while(completed<n){
        int idx=-1;
        for(i=0;i<n;i++){
            if(rem[i]>0 && at[i]<=time){
                if(idx==-1 || pr[i]<pr[idx] ||
                  (pr[i]==pr[idx] && rem[i]<rem[idx]) ||
                  (pr[i]==pr[idx] && rem[i]==rem[idx] && at[i]<at[idx]))
                    idx=i;
            }
        }
        if(idx==-1){ exec[k++]=-1; time++; continue; }
        exec[k++]=idx;
        rem[idx]--;
        time++;
        if(rem[idx]==0){
            ct[idx]=time;
            completed++;
        }
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(i=0;i<k;i++){
        if(exec[i]==-1) printf("idle ");
        else printf("P%d ",exec[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
        printf("P%d %d %d %d %d %d %d\n",i,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}
