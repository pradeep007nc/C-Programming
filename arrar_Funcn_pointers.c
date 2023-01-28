#include<stdio.h>

void add(int a,int b){
    printf("%d",a+b);
}
void sub(int a,int b){
   printf("%d",a+b);
}
void mult(int a,int b){
    printf("%d",a+b);
}

int main(){
    void (*arr_ptr[])(int, int)={add,sub,mult};
    int a=10;
    int b=15;
    arr_ptr[0](a,b);
    return 0;
}