#include<stdio.h>
#define LEN 100

typedef struct{
    char arr[LEN];
}String;

int findLen(String *ptr){
    int count=0;
   for(int i=0;i<ptr->arr[i]!='\0';i++){
     count++;
   }
   return count;
}

void concatStr(String *str1,String *str2, String *str3){
    int len1=findLen(str1);
    int len2=findLen(str2);
    
    int count=0;
    for(int i=0;i<len1;i++){
        str3->arr[i]=str1->arr[i];
    }
    for(int j=len1;j<len1+len2;j++){
        str3->arr[j]=str2->arr[count++];
    }
}

int main(){
    String s1,s2,s3;
    printf("\nenter two strings");
    scanf("%s%s",&s1.arr,&s2.arr);
    concatStr(&s1,&s2,&s3);
    printf("\n%s \n%s \nconacatenated is :%s",s1.arr,s2.arr,s3.arr);
    return 0;
}