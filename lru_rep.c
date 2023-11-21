#include<stdio.h>


int lru(int time[] , int nf){
    int i,min = time[0] , pos =0;
    
    for(i=1 ; i<nf ; i++){
        if(time[i]< min){
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    int np,nf,counter=0,pf=0,flag1,flag2,i,j;
    printf("enter no of pages");
    scanf("%d",&np);
    int pages[np];
    
    printf("enter no of frames");
    scanf("%d",&nf);
    int frames[nf];
    
    int time[10];
    
    printf("enter no of pages sequence");
    for( i=0;i<np;i++){
        scanf("%d",&pages[i]);
    }
    
     for( i=0;i<nf;i++){
        frames[i] = -1;
    }
    
    for(i=0 ; i<np ; i++){
        flag1=flag2=0;
        
        for(j=0 ; j<nf ; j++){
            if(pages[i]==frames[j]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        
        if(flag1 == 0){
            for(j=0 ; j<nf ; j++){
                if(frames[j] == -1){
                    pf++;
                    counter++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        
        if(flag2 == 0){
            int pos = lru(time,nf);
            counter++;
            pf++;
            frames[pos] = pages[i];
            time[pos] = counter;
            
        }
        
        printf("\n");
        for(j=0 ; j<nf ; j++){
            printf("%d\t",frames[j]);
        }
    }
     printf("\n");
    printf("no of pf = %d",pf);
}
