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
int substring(char* str1, char* str2)
{
	int len = Length(str1);
	int len1 = Length(str2);
	int i = 0;
	int j = 0;
	int counter = 0;
	while (i < len)
	{
		while (str1[i] == str2[j]&&j<len1)
		{
			counter++;
			j++;
			i++;
	    }
		if (counter > 0)
		{
			if (counter == len1)
			{
				return 1;
			}
		}
		j = 0;
		i++;
		counter = 0;
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
        if(similar(word, str)) printf ("%s\n", word);
    }
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
}