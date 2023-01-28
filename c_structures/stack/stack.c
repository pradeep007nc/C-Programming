#include<stdio.h>
#include<stdlib.h>
 struct stack{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack* ptr,int val ){
    if(isfull(ptr)){
        printf("\nnahi ho payega bhai");
        return;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    } 
    printf("\npushed sucesfully");
}

int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack is already empty");
    }
    else{
         int popval=ptr->arr[ptr->top];
         ptr->top--;
         return popval;
    }
   return 0;
}

void stackdisplay(struct stack *ptr,int size){
    if(ptr->top==-1){
        printf("\nstack is empty");
    }else{
        for(int i=0;i<=size;i++){
        printf("\nelements in stack are:%d",ptr->arr[i]);
    }
    }
}

int peek(struct stack *ptr){
    int val = ptr->arr[ptr->top];
    return val;
}



int main(){
    struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
    s1->size=10;
    s1->top=-1;
    s1->arr=(int *)malloc(s1->size*sizeof(int));
   
    printf("\npopped val is:%d",pop(s1));
    stackdisplay(s1,s1->top);
    printf("\npeek value is :%d",peek(s1));
    return 0;
}