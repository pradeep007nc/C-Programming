#include<stdio.h>

typedef struct
{
    float num,den;
}ratioanal;

typedef enum{
    true,
    false
}bool_choose;

ratioanal minus(ratioanal x, ratioanal y);
ratioanal additon(ratioanal x,ratioanal y);
ratioanal multiplication(ratioanal x,ratioanal y);

int main(){
    ratioanal r1,r2,add,sub,mul;
    printf("Enter the 1st rational number");
    scanf("%f%f",&r1.num,&r1.den);
    printf("enter 2nd rational number");
    scanf("%f%f",&r2.num,&r2.den);
    bool_choose x=true;

    while(x==true){
        int choice;
        printf("Choose \n1.ADD\n2.SUB\n3.MUL");
        scanf("%d",&choice);

        if(choice==4){
            break;
        }

        switch (choice)
        {
        case 2:sub=minus(r1,r2);
            printf("the subtraction of values is %.2f\n",sub);
            break;

        case 1:add=additon(r1,r2);
            printf("the addition of values is %.2f\n",add);
            break;

        case 3:mul=multiplication(r1,r2);
            printf("the multiplication of values is %.2f",&mul);
            break;

        default:
            printf("bsdk sirf 4 options avl");
            break;
        }
    }
    return 0;
}

ratioanal additon(ratioanal x,ratioanal y){
    ratioanal ans;
    ans.num=(x.num*y.den+y.num*x.den)/x.den*y.den;
    return ans;
}

ratioanal minus(ratioanal x,ratioanal y){
    ratioanal ans;
    ans.num=(x.num*y.den-y.num*x.den)/x.den*y.den;
    return ans;
}


ratioanal multiplication(ratioanal x,ratioanal y){
    ratioanal ans;
    ans.num=x.num*y.num/x.den*y.den;
    return ans;
}