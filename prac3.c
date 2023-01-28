#include<stdio.h>
#define SIZE 50

typedef struct 
{
    char name[SIZE];
    char month[SIZE];
    char day[SIZE];
    int year;
    int salary;

}employee;

int main(){
    employee emp;
    scanf("%s%s%s %d%d",&emp.name,&emp.month,&emp.day,&emp.year,&emp.salary);
    printf("name is %s\nmonth is  %s\nday is %s\nyear is%d\nsal is %d",emp.name,emp.month,emp.day,emp.year,emp.salary); 
    return 0;
}

