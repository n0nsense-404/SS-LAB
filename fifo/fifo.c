#include <stdio.h>

int main() {
    int i,j,k,count=0,flag=0,pn,fn;
    int pages[20],frames[20];
    
    printf("Enter No of pages: ");
    scanf("%d",&pn);
    
    for(i=0;i<pn;i++){
        printf("Enter Page no %d: ",i+1);
        scanf("%d",&pages[i]);
    }
    
    printf("Enter No of Frames: ");
    scanf("%d",&fn);
    
    for(i=0;i<fn;i++){
        frames[i] = 0;
    }
    
    j = 0;
    
    printf("\nPages: ");
    for(i=0;i<pn;i++){
        printf("%d ",pages[i]);
    }
    
    printf("\nFrames: \n");
    for(i=0;i<pn;i++){
        flag=0;
        for(k=0;k<fn;k++)
            if(pages[i]==frames[k])
                flag = 1;
        if(flag==0){
            count ++;
            frames[j] = pages[i];
            j = (j+1)%fn;
            for(k=0;k<fn;k++){
                printf("%d ",frames[k]);
            }
            printf("\n");
        }
    }
    
    printf("\nNo of Page Faults = %d",count);
}
