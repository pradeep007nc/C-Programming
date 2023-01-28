#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float real,imag;
}complex;

typedef enum{
    true,
    false
}bool_enum;

complex sum(complex x,complex y);
complex min(complex x,complex y);
complex mult(complex x,complex y);

int main(){
    complex cmp1,cmp2,add,sub,mul;
    bool_enum i=true;
    while(i==true){
        int choice;
        printf("enter choice:\n1.ADD \n2.SUB\n3.MUL\n");
        scanf("%d",&choice);
        if(choice==4){
            break;
        }else{
        printf("\n Enter real and imag of 1st complex number");
        scanf("%f %f",&cmp1.real,&cmp1.imag);
         printf("\n Enter real and imag of 2nd complex number");
        scanf("%f %f",&cmp2.real,&cmp2.imag);

        switch (choice)
        {
        case 1:
            add=sum(cmp1,cmp2);
            printf("\n The addition of values is %.2f adn %.2fi\n",add.real,add.imag);
            break;
        
          case 2:
            sub=min(cmp1,cmp2);
            printf("\n The subtraction of values is %.2f adn %.2fi\n",sub.real,sub.imag);
            break;
        
         case 3:
            mul=mult(cmp1,cmp2);
            printf("\n The multiplication of values is %.2f adn %.2fi\n",mul.real,mul.imag);
            break;

        default:
        printf("invalid input enter only between 1-4");
            break;
        }
     }
    }
    return 0;
}

complex sum(complex x,complex y){
    complex res;
    res.real=x.real+y.real;
    res.imag=x.imag+y.imag;
    return res;
}

complex min(complex x, complex y){
    complex res;
    res.real=x.real-y.real;
    res.imag=x.imag-y.imag;
    return res;
}

complex mult(complex x,complex y){
    complex res;
    res.real=x.real*y.real-x.imag*y.imag;
    res.imag=x.real*y.imag+y.real*x.imag;
    return res;
}