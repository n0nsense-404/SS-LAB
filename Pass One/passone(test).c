#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    FILE *f1,*f2,*f3,*f4;

    int locctr,x;

    char one[50],two[50],three[50];
    char one1[50],two1[50];

    f1 = fopen("input.txt","r");
    f2 = fopen("opcode.txt","r");
    f3 = fopen("out.txt","w");
    f4 = fopen("sym.txt","w");

    while(fscanf(f1,"%s%s%s",one,two,three)!=EOF){
        if(strcmp(one,"**")==0){
            if(strcmp(two,"START")==0){
                fprintf(f3,"%s%s%s",one,two,three);
                locctr = atoi(three);
            }

            else{
                rewind(f2);
                x=0;
                while(fscanf(f2,"%s%s",one1,two1)!=EOF){
                    if(strcmp(two,two1)!=0)
                        x=1;
                }
                if(x==1){
                        fprintf(f3,"\n%d%s%s%s",locctr,one,two,three);
                        locctr += 3;
                }
            }
        }
        else{
            if(strcmp(two,"RESW")==0){
                fprintf(f3,"\n%d%s%s%s",locctr,one,two,three);
                fprintf(f4,"\n%d%s",locctr,one);
                locctr += (3*atoi(three));
            }
            else if(strcmp(two,"WORD")==0){
                fprintf(f3,"\n%d%s%s%s",locctr,one,two,three);
                fprintf(f4,"\n%d%s",locctr,one);
                locctr += 3;
            }
            else if(strcmp(two,"RESB")){
                fprintf(f3,"\n%d%s%s%s",locctr,one,two,three);
                fprintf(f4,"\n%d%s",locctr,one);
                locctr += 1;
            }
            else if(strcmp(two,"BYTE")){
                fprintf(f3,"\n%d%s%s%s",locctr,one,two,three);
                fprintf(f4,"\n%d%s",locctr,one);
                locctr += 1;
            }
            else{
                fprintf(f3,"\n%d%s%s%s",locctr,one,two,three);
                fprintf(f4,"\n%d%s",locctr,one);
                locctr += (3*(atoi(three)));
            }
        }
    }
}
