#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define MAXLINES 250

int getLine(char s[]){
    int i=0;
    scanf("%c",&s[i]);

    while(i<LINE && s[i] != '\n' && s[i] != '\r'){

        i++;
        if(scanf("%c",&s[i])==EOF) return 0;
        }

        s[i]='\0';
        return (i+1);
    } 

int getWord(char w[]){
    int i=0;
    scanf("%c",&w[i]);

    while(i<WORD && w[i] != '\n' && w[i] != '\t' && w[i] != ' ' && w[i] != '\r'){

        i++;
        if(scanf("%c",&w[i])==EOF) return 0;

        }
        w[i]='\0';
        return (i+1);
    } 

int substring( char * str1, char * str2){
    if(strlen(str1)<strlen(str2))
        return 0;

    int i=0;
    for(int j=0;j<strlen(str1);j++){

        if(str1[j]==str2[0]){
            i=1;

           while(i<strlen(str2) && (j+i)<strlen(str1)&& str1[i+j]==str2[i])
                i++;

            if(i==strlen(str2))   
            return 1; 
            }
        }
        return 0;
    }
     

int similar (char *s, char *t){
    int i=0;
    int count=0;
    if(strlen(s)!= strlen(t)+1)
    return 0;

    for(int j=0;j<strlen(s) && i<strlen(t);j++){

        if(s[j]==t[i])
            i++;
        else count++; 

    }
    if(count>1) 
        return 0;

    return 1;    
}

void printLines(char * str){
    char line[LINE]={0};
    int size;

    for (int i = 0; i < MAXLINES; i++){
        size=getLine(line);

        if(size==0)
        break;

        if(substring(line,str)==1)
             printf("%s\n", line);
}
}

void printSimilarWords(char * str){
    char check[WORD]={0};
    int size;
    for (int i = 0; i < MAXLINES*LINE; i++){
        size=getWord(check);
        if(size==0)
        break;
        

        if(similar(check,str)==1 ||strcmp(check,str)==0)
                printf("%s\n", check);

    } 
    }


int main(){
    char word[WORD]={0};
    getWord(word);
    char function[WORD]={0};
    getWord(function);

    if(function[0]=='a')
    printLines(word);

    if(function[0]=='b')
    printSimilarWords(word);

    return 0;
}