#include<stdio.h>
int main(){
    int a=50;
    float b=30.0;
    char c='A';
    double d=123.132;
    char arr[]="mama mia";
    char* ptr=arr;
    int* ptr1=&a;
    char sum;
    float* floatptr;
    char* charptr;
    double* doubleptr;
    printf("%d   %d ",sizeof(ptr1),sizeof(a));
    printf("%d   %d ",sizeof(floatptr),sizeof(b));
    printf("%d   %d ",sizeof(doubleptr),sizeof(d));
    printf("%d   %d ",sizeof(charptr),sizeof(c));
    printf("%d   %d ",sizeof(ptr),sizeof(arr));
  
   for (int i=0;i<sizeof(arr);i++){
    printf("%c",*ptr++);
    sum=*ptr;
    printf("%c",sum);
   }
 
    return 0;
}