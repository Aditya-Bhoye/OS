#include<stdio.h>
int main(){
    int n,f,i,j,k,fault=0,hit=0;
    int pages[50],frames[10];
    printf("Enter number of pages you want : ");
    scanf("%d",&n);
    printf("Enter number of frames you want : ");
    scanf("%d",&f);
    printf("Enter page reference string : ");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<f;i++){
        frames[i] = -1;
    }
    printf("Page\t");
    for(i=0;i<f;i++){
        printf("F%d\t",i);
    }
    printf("Status\n");
    for(i=0;i<n;i++){
        int found = 0;
        for(j=0;j<f;j++){
            if(frames[j] == pages[i]){
                found = 1;
                break;
            }
        }
        if(found){
            hit++;
            printf("%d\t",pages[i]);
            for(j=0;j<f;j++){
                if(frames[j]==-1) printf("-\t");
                else printf("%d\t",frames[j]);
            }
            printf("Hit\n");
        }
        else{
            int pos = -1;
            for(j=0;j<f;j++){
                if(frames[j] == -1){
                    pos = j;
                    break;
                }
            }
            if(pos == -1){
                int farthest = -1;
                for(j=0;j<f;j++){
                    int found_future = 0;
                    for(k=i+1;k<n;k++){
                        if(frames[j] == pages[k]){
                            if(k > farthest){
                                farthest = k;
                                pos = j;
                            }
                            found_future = 1;
                            break;
                        }
                    }
                    if(found_future == 0){
                        pos = j;
                        break;
                    }
                }
            }
            frames[pos] = pages[i];
            fault++;
            printf("%d\t",pages[i]);
            for(j=0;j<f;j++){
                if(frames[j]==-1) printf("-\t");
                else printf("%d\t",frames[j]);
            }
            printf("Fault\n");
        }
    }
    printf("Total Fault %d\n",fault);
    printf("Total Hit %d\n",hit);
}
