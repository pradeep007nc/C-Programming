#include <stdio.h>
#include <stdlib.h>
#define SSIZE 5

typedef struct
{
    int top;

    struct
    {
        char name[20];
        int age;
        int total;
    } student[SSIZE];

} stack;

int isFull(stack *s1)
{
    if (s1->top > SSIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *s1)
{
    char inputName[20];
    int inputAge;
    if (!(isFull(s1)))
    {
        s1->top++;
        printf("Enter Student name:");
        scanf("%s", s1->student[s1->top]->name);
        printf("Enter Student age:");
        scanf("%d", &s1->student->age);
        printf("Enter Student total:");
        scanf("%d", &s1->student->total);
    }
    else
    {
        printf("\nStack is full\nCant add more elements\n");
    }
}

int isEmpty(stack *s1)
{
    if (s1->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pop(stack *s1)
{
    if(!isEmpty(s1))
    {
        printf("\nDeleted the Student Details of %s",s1->student->name);
        s1->top--;
    }
    else{
        printf("\nStack is Empty\nCannot Pop");
    }
}

void peek(stack *s1)
{
    int val = s1->top;
    printf("\nTop Element = %d", val);
    printf("\nStudent Name=%s \tAge=%d \tTotal=%d", s1->student->name, s1->student->age, s1->student->total);
}
    
void display(stack *s1)
{
    
        printf("\n%s\t%d\t%d",s1->student->name,s1->student->age, s1->student->total);
        
}


int main()
{
    stack s1;

    s1.top = -1;
    int pushelement;

    int choice = 0;
    do
    {

        printf("\n0.Exit");
        printf("\n1.Push Element");
        printf("\n2.Pop Top Element");
        printf("\n3.Peep on Top element");
        printf("\n4.Display all Stack Elements from Top");
        printf("\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(&s1);
            break;
        case 2:
            pop(&s1);
            break;
        case 3:
            peek(&s1);
            break;
        case 4:
            display(&s1);
            break;
        default:
            break;
        }

    } while (choice != 0);

    return 0;
}