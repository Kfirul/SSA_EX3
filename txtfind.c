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
int similar (char *s, char *t,int n){ 
   int count=0;
   int i=0;
   int j;
    for( j=0;j<strlen(t)&& i<strlen(s);j++){
        if(s[i]==t[j]){
            i++;
        }     else count++;
    }
   if(count==n && j==strlen(t)) return 1;
    return 0;
}
int substring(char* str1, char* str2){
    int j;
    for (int i = 0 ; i < strlen(str1)-strlen(str2)+1 ; i++){
        if (str1[i] == str2[0]){
            for (j = 0 ; j < strlen(str2) ; j++){
                if (str1[i+j]!= str2[j]){
                    break;
                }
            }
            if (j == strlen(str2)){
                return 1;
            }
        }
    }
    return 0;
}
void print_lines(char * str){
    char text[MAXLINES] = {0};
    int count=0;
    while(count<MAXLINES){
        getLine(text);
        count++;
        if(substring(text,str)){
            printf("%s\n", text);
        }
        if(text[0]== '\0') break;
    }
}
void print_similar_words(char * str){
    char word[WORD]= {0};
    int count =0;
    while(count< MAXLINES*LINE){
        getword(word);
        count++;
    if(similar(word, str,0)==1 || similar(word, str,1)==1) printf ("%s\n", word);    }
}


int main(){
    char function = '\0';
    char word [WORD]= {0};
    scanf("%s %c", word, &function);
    char emptyLine[LINE]= {0};
    getLine(emptyLine);

    if(function== 'a'){
        char temp[LINE]={0};
        getLine(temp);
        print_lines(word);
    }
    if(function== 'b'){
        char emptyLine[LINE]={0};
        getLine(emptyLine);
        print_similar_words(word);
    }
    return 0;
}