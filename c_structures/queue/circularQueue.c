#include<stdio.h>
#define SIZE 10
#include<stdbool.h>

typedef struct{
    int size;
    int front;
    int rear;
    int arr[SIZE];
}circularQueue;

bool isFull(circularQueue *ptr){
  return (ptr->size == SIZE) ? true : false;
}

bool isEmpty(circularQueue *ptr){
    return (ptr-> size == 0) ? true : false;
}

void enQueue(circularQueue *ptr, int val){
  if (isFull(ptr) == false){
    ptr->rear = (ptr->rear+1)%SIZE;
    ptr->arr[ptr->rear] = val;
    ptr -> size++;
    printf("%d is sucessfully inserted\n", val);
  }else{
    printf("queue is full\n");
  }
}

int deQueue(circularQueue *ptr){
   if (isEmpty(ptr) == false){
     ptr->front = (ptr->front+1)%SIZE;
     int item = ptr->arr[ptr->front];
     printf("%d is sucessfully deleted\n", item);
     ptr->size--; 
     return item;
   }else{
    printf("queue is Empty\n");
   }
}

void queueDisplay(circularQueue *ptr){
   if(ptr->front <= ptr->rear){
    for (int i = ptr->front; i <= ptr->rear; i++)
    {
        printf("the val is %d\n", ptr->arr[i]);
    }
   }else if(ptr->front > ptr->rear){
    for(int i=ptr->front+1;i<SIZE;i++){
        printf("the val is %d\n", ptr->arr[i]);
    }
    for(int j=0; j<=ptr->rear;j++){
        printf("the val is %d\n", ptr->arr[j]);
    }
   }
}

 int main(){
    circularQueue cq;
    int n, val;
    printf("enter the front and rear\n");
    scanf("%d%d", &cq.front, &cq.rear);
    do{
            printf("enter 1 to enQueue\n");
            printf("Enter 2 to deQueue.\n");
            printf("enter 3 to displayQueue\n");
            printf("any other number to exit\n");       
            printf("enter choice\n");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("enter the value to be inserted into queue\n");
                scanf("%d", &val);
                enQueue(&cq, val);
                break;
            
            case 2:
                deQueue(&cq);
                break;
            
            case 3:
                queueDisplay(&cq);
                break;
            
            default:
                printf("invalid choice\n");
                break;
            }
    }while(n>=0 && n<=3);
    return 0;
 }