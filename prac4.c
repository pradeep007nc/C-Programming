#include<stdio.h>
#define SIZE 100

int strLen(char str[])
{ 
    int count=0;
    int size=0;
    while (str[size++]!='\0')
    {
        count++;
    }
    return count;
    
}

void strConcat(char str1[],char str2[]){
    char str[100];
    int count=0;
    int i=0;
    int j=0;
    while (str2[i]!='\0')
    {
        int string1=strLen(str1);
        str1[string1++]=str2[i++];
    }
   str[count++]=str2[j++];
}

void substr(char str1[],int start,int end){
    char ans[SIZE];
    int count=0;
    for(int i=start;i<end;i++){
       ans[count++]=str1[i];
    }
    printf("\n %s",&ans);
}


int main(){
    char str[SIZE];
    int strLength;
    char concat[SIZE];
    printf("\nenter a string");
    scanf("%s",&str);
    strLength=strLen(str);
    printf("\nthe string length is %d",strLength);
    
    char str1[SIZE];
    char str2[SIZE];
    printf("\nenter string 1");
    scanf("%s",&str1);
    printf("\nenter string 2");
    scanf("%s",&str2);
    strConcat(str1,str2);
    printf("\nthe concatenated string is %s",str1);

    printf("\nenter the start position");
    int start;
    scanf("%d",&start);
    printf("\nenter the end position");
    int end;
    scanf("%d",&end);
    substr(str1,start,end);



    return 0;
}