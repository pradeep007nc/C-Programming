#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct
{
    int items[MAXSIZE];
    int front;
    int rear;
} queue;
int isempty(queue *q)
{
    if((q->front==0 && q->rear==0) || (q->front==-1 && q->rear==-1))
    {
        if(q->front==q->rear)
            return 1;
        else 
            return 0;
    }
    else if(q->front==0 && q->rear==-1)
    {
        if(q->front==q->rear+1)
            return 1;
        else
            return 0;
    }
    else if(q->front==-1 && q->rear==0)
    {
        if(q->front==q->rear-1)
            return 1;
        else
            return 0;
    }
}
int isfull(queue *q)
{
    if((q->front==0 && q->rear==0) || (q->front==-1 && q->rear==0))
    {
        if(q->rear==MAXSIZE)
            return 1;
        else
            return 0;
    }
    else if((q->front==0 && q->rear==-1) || (q->front==-1 && q->rear==-1))
    {
        if(q->rear==MAXSIZE-1)
            return 1;
        else 
            return 0;
    }
}
void enqueue(queue *q,int n)
{
    int ele;
    printf("\nEnter the item to be inserted:");
    scanf("%d",&ele);
    if(n==1)
        printf("\nQueue overflow");
    else if((q->front==0 && q->rear==0) || (q->front==-1 && q->rear==0))
    {
        q->items[(q->rear)++]=ele;
    }
    else if((q->front==0 && q->rear==-1) || (q->front==-1 && q->rear==-1))
    {
        q->items[++(q->rear)]=ele;
    }
}
void dequeue(queue *q,int n)
{
    int ele;
    if(n==1)
        printf("\nQueue underflow");
    else
    {
        if((q->front==0 && q->rear==0) || (q->front==0 && q->rear==-1))
        {
            ele=q->items[(q->front)++];
        }
        else if((q->front==-1 && q->rear==0) || (q->front==-1 && q->rear==-1))
        {
            ele=q->items[++(q->front)];
        }
        printf("\nItem being deleted is: %d",ele);
    }
}
void unqueue(queue *q,int n)
{
    int ele;
    if(n==1)
        printf("\nQueue underflow");
    else if((q->front==0 && q->rear==0) || (q->front==0 && q->rear==-1))
    {
        ele=q->items[(q->front)++];
    }
    else if((q->front==-1 && q->rear==0) || (q->front==-1 && q->rear==-1))
    {
        ele=q->items[++(q->front)];
    }
}
void requeue(queue *q,int n)
{
    int ele;
    if(n==1)
        printf("\nQueue underflow");
    else
    {
        if(q->front==0 && q->rear==0)
        {
            ele=q->items[(q->front)++];
            q->items[(q->rear)++]=ele;
        }
        else if(q->front==0 && q->rear==-1)
        {
            ele=q->items[(q->front)++];
            q->items[++(q->rear)]=ele;
        }
        else if(q->front==-1 && q->rear==0)
        {
            ele=q->items[++(q->front)];
            q->items[(q->rear)++]=ele;
        }
         else if(q->front==-1 && q->rear==-1)
        {
            ele=q->items[++(q->front)];
            q->items[++(q->rear)]=ele;
        }
    }     
}
void qdisplay(queue *q,int n)
{
    int i;
    if(n==1)
        printf("\nNo elements are present in the queue");
    else
    {
        for(i=q->front;i<=q->rear;i++)
            printf("%d ",q->items[i]);
    }
}
int main()
{
    int i=1,ch,n;
    queue q;
    printf("\nEnter the values of front and rear:");
    scanf("%d%d",&q.front,&q.rear); 
    while(i=1)
    {
        printf("\nEnter your choice \n1.Enqueue \n2.Dequeue \n3.Unqueue \n4.Requeue \n5.Display \n6.Exit:");
        scanf("%d",&ch); 
        switch(ch)
        {
            case 1: n=isfull(&q);
                    enqueue(&q,n);
                    break;
            case 2: n=isempty(&q);
                    dequeue(&q,n);
                    break;
            case 3: n=isempty(&q);
                    unqueue(&q,n);
                    break;
            case 4: n=isempty(&q);
                    requeue(&q,n);
                    break;
            case 5: n=isempty(&q);
                    qdisplay(&q,n);
                    break;
            case 6: exit(0);
            default: printf("\nEnter valid choice");
        }
    }
    return 0;
}