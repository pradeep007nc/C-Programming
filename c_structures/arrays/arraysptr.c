#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>



typedef struct{
    int top;
    struct{
    char name[50];
    int marks[5];
    int rollno;
  }student[5];

}stack;

int studentcounter=0;
int namectr=0;


bool isempty(stack *ptr){
    if(ptr->top==-1){
        return true;
    }else{
        return false;
    }
}

void push(stack *ptr){
           
        ptr->student[studentcounter].rollno=rand() % 100 + 1;
        ptr->top++;
        if(!(isempty(ptr))){
            printf("name enter maar bsdk");
          scanf("%s",ptr->student[studentcounter++].name);
         }else{
            printf("not sucessful");
         }
     } 
  

int main(){
    stack stk1;
    stk1.top=-1;
    char name[]="mia";
    push(&stk1);

    

    return 0;
}