#include<stdio.h>
#include<stdbool.h>

typedef struct {
    int top;
    char arr[100];
}stack;

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
int main(){
    stack s1;
    s1.top=-1;
    char post[50];
    char expr[]={"A+B*E(F+g)"};
    if(checkValidity(&s1, expr)){
        printf("\nvalid o maga\n");
        convertPostfix(&s1, expr, post);
        stackdisplay(&s1, len(expr));
        for(int i=0;post[i]!='#';i++){
            printf("%c",post[i]);
        }
    }else{
        printf("\ninvalid maga");
    }
    
}