#include<stdio.h>
#include <stdlib.h> 
#include<string.h>
#define SIZE 100

typedef struct 
{
    char* name[SIZE];
    int age;   
    int sub1,sub2,sub3,sub4,sub5;
    int marks;
    float classavg;
    float subavg;
}Student[SIZE];


int main(){
    Student s1,s2;
    char* names[SIZE]={"Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan","Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan"  };
    for (int i = 0; i < SIZE; i++)
    {
      s1[i].age=rand() % (35 + 1 - 18) + 18;
      s1[i].sub1=rand() % 100 + 1;
      s1[i].sub2=rand() % 100 + 1;
      s1[i].sub3=rand() % 100 + 1;
      s1[i].sub4=rand() % 100 + 1;
      s1[i].sub5=rand() % 100 + 1;
      s1[i].marks=rand() % 500 + 1;
      s1->classavg+=s1[i].marks;
      s1->subavg+=s1[i].marks/5;
    }
    
    s2->classavg=s1->classavg/SIZE%100;
    s2->subavg=s1->subavg/SIZE;

     for (int i = 0; i < SIZE; i++)
    {
      printf(" \nStudent %d :Name is %s: \nAge is:%d \nMarks is %d: \nSub 1:%d \nSub 2:%d \nSub 3:%d \nSub 4:%d \nSub 5:%d ",i+1,names[i],s1[i].age,s1[i].marks,s1[i].sub1,s1[i].sub2,s1[i].sub3,s1[i].sub4,s1[i].sub5);
    }
     printf("\nclass average is %.2f",s2->classavg);
     printf("\nsub avg is %.2f",s2->subavg);
    return 0;
}