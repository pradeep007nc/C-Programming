#include<stdio.h>
#include<stdlib.h>

typedef struct{
    float height;
    int weight;
}person[10];

int main(){
    person p1;
    int temp=0;
    int index=0;
    int calc=0;
    for(int i=0;i<10;i++){
        p1[i].height=rand()%(200-50+1)+50*0.0254;
        p1[i].weight=rand()%(100-50+1)+50;  
        temp=p1[i].weight/(int)(p1[i].height*p1[i].height);
        if(calc<=temp){
            printf("hi im here");
          calc=temp;
          index=i;
        } 
    }

    printf("the bmi max is %d from %d person",calc,index);
    return 0;
}