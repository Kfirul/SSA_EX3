#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define MAXLINES 250

int getLine(char s[]){
    int i;
    int count=0;
    for(i=0;i<LINE;i++){
        scanf("%c",&s[i]);

        if(s[i] == '\n' ||  s[i]=='\r')
        {
            s[i]='\0';
            break;
        }
        count++;
    }
    
    return count;
}

int getword(char w[]){
    int i;
    int count=0;
    for(i=0;i<WORD;i++){
        scanf("%c",&w[i]);

        if(w[i] == '\n' || w[i] == '\t' || w[i] == ' ' || w[i]=='\r')
        {
            w[i]='\0';
            break;
        }
        count++;
    }
    
    return count;
}
int similar (char *s, char *t){
   
    if(strlen(s)+1!=strlen(t))
    return 0;
    int sim;
    int index;
    for(int i=0;i<strlen(t);i++){
        index=0;
        sim=1;
        for (int j = 0; j < strlen(t) && sim==1; j++)
        {
            if(i==j) 
                j++;

           else  if(*(s+index)!=(*(t+j)))
                sim=0;
        index++;        
        }
        if(sim==1)
        return 1;
        
    }
    return 0;
}
void print_lines(char * str){

}


int main(){
// char w[WORD];
// int num=getword(w);
// printf("%d",num);
// char s[LINE];
// int numLines=getLine(s);
// printf("%d",numLines);
char w[]={'a', 'b', 'c', '\0'};
char z[]={'a', 'x', 'b','c','c' ,'\0'};
int sim=similar(w,z);
printf("%d",sim);
return 1;
}