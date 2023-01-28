#include<stdio.h>
#include<stdbool.h>

typedef struct {
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


void convertPostfix(stack *ptr,char expr[], char *post[]){    
   for(int i=0;expr[i]!='\0';i++){
    char val;
    push(ptr, '(');
    int length = len(expr);
    expr[length] = ')';
    int index = 0; 
    if(expr[i] == '(')  push(ptr, expr[i]);
    else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){
        if(precedence(ptr, peek(ptr)) <= precedence(ptr, expr[i])){
            push(ptr, expr[i]);
        }else{
            post[index++] = pop(ptr);
            push(ptr, expr[i]);
        }
    }
    else if(expr[i] == ')'){
        while(val != '('){
            val = pop(ptr);
            post[index++] = val;
        }
    }else{
        post[index++] = expr[i];
    }
   }
   printf("%s",post);
}

int main(){
    stack s1;
    s1.top=-1;
    char post[50];
    char expr[]={"A+B*E-(F+g)"};
    if(checkValidity(&s1, expr)){
        printf("\nvalid o maga\n");
        convertPostfix(&s1, expr, &post);
        printf("%s", post);
    }else{
        printf("\ninvalid maga");
    } 
}