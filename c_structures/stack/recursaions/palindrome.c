#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int top;
    char arr[100];
}stack;

int len(char arr[]){
    int count=0;
    for(int i=0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}

int isempty( stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isfull( stack *ptr){
    if(ptr->top==sizeof(ptr->arr)-1){
        return 1;
    }else{
        return 0;
    }
}

void push( stack* ptr,int val ){
    if(isfull(ptr)){
        printf("\nnahi ho payega bhai");
        return;
    }else{
        ptr->arr[++ptr->top]=val;
    } 
}

char pop( stack *ptr){
    if(isempty(ptr)==false){
        char popval=ptr->arr[ptr->top--];
         return popval;
    }
    else{
          printf("stack is already empty");
    }
}


char peek(stack *ptr){
    char val = ptr->arr[ptr->top];
    return val;
}


void stackdisplay(stack *ptr,int size){
    if(ptr->top==-1){
        printf("\nstack is empty");
    }else{
        for(int i=0;i<=ptr->top;i++){
        printf("\nelements in stack are:%c\n",ptr->arr[i]);
    }
    }
}

bool checkValidity(stack *ptr, char expr[]){
    char val;
    int length=len(expr);
    for(int i=0;i<length;i++){
        if(expr[i]=='[' || expr[i]=='{' || expr[i]=='('){
            push(ptr, expr[i]);
        }else if(expr[i]==']' || expr[i]=='}' || expr[i]==')'){
            if(expr[i]==']'){ 
                val = pop(ptr);          
                if(val != '['){
                    return false;
                 }
            }
            else if(expr[i]=='}'){
                val = pop(ptr);
                if(val != '{'){
                    return false;
                    }
            }
            else if(expr[i]==')'){
                    val = pop(ptr);
                     if(val != '('){
                    return false;
                    }
                }
           }
        }
        if(isempty(ptr)==1){
            return true;
        }
        return false;
}

int precedence(stack *ptr, char val){
    if(val == '+' || val == '-'){
        return 1;
    }else if(val == '*' || val == '/'){
        return 2;
    }else{
        return 3;
    }
}


char infToPost(stack *ptr, int count, char expr[], char *post[]){
   if(count == len(expr)) return post;
   count++;

    if(expr[count] = '+' || expr[count] = '-' || expr[count] = '*' || expr[count] = '/'){
      if(precedence(ptr, expr[i]) >= peek(ptr))  push(ptr, expr[i]);
      
    }
}


int main(){
    stack s1;
    char expr[] = "(a+b*c)";
    char post[100];
    if(checkValidity(&s1, expr)){
        printf("valid expr can continue\n");
        printf("enter from 1-3");
        int n;
        scanf("%d",&n);
        // switch(n){
        //     case 1:infToPost(&s1, expr, post);
        // }
    }else{
        printf("not a void expression");
    }
    return 0;
}
