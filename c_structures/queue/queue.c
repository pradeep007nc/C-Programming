#include<stdio.h>
#include<stdbool.h>
#define SIZE 100

typedef struct{
    int front;
    int rear;
    int arr[SIZE];
}Queue;

int isFull(Queue *ptr){
    return (ptr-> rear == SIZE) ? 1 : 0; 
}

int isFull2(Queue *ptr){
   return (ptr-> rear == SIZE - 1) ? 1 : 0; 
}

bool isEmpty(Queue *ptr){
    if(ptr->rear == ptr->front-1){
        return true;
    }
    return false;
}

bool isEmpty1(Queue *ptr){
    if(ptr->rear == ptr->front) return true;
    return false;
}

void insert(Queue *ptr, int val){
    if(isFull(ptr) == 0){
       ptr->arr[ptr->rear++] = val;
    }else{
        printf("full\n");
    }
}

void insert2(Queue *ptr, int val){
    if(isFull2(ptr) == 0){
       ptr->arr[++ptr->rear] = val;
    }else{
        printf("its full\n");
    }
}

void queueDisplay(Queue *ptr, int front){
   if(front == 0){
    for(int i=ptr->front;i<ptr->rear;i++){
        printf("value is :%d\n", ptr->arr[i]);
    }
   }else{
    for(int i=ptr->front+1;i<ptr->rear;i++){
         printf("value is :%d\n", ptr->arr[i]);
    }
   }
}

void queueDisplay2(Queue *ptr, int front){ 
    if(front == 0){
    for(int i=ptr->front;i<=ptr->rear;i++){
        printf("value is :%d\n", ptr->arr[i]);
    }
   }else{
    for(int i=ptr->front+1;i<=ptr->rear;i++){
         printf("value is :%d\n", ptr->arr[i]);
    }
   }
}

int delete(Queue *ptr){
    int val;
    if(isEmpty1(ptr)!=false){
       val = ptr->arr[++ptr->front];
       return val;
    }
    printf("its empty\n");
}

int delete2(Queue *ptr){
    int val;
    if(isEmpty(ptr)!=false){
        val = ptr->arr[ptr->front++];
        return val;
    }
    printf("its empty\n");
}

void unQueue(Queue *ptr){
     if(isEmpty1(ptr)!=false){
         ptr->arr[++ptr->front];
    }
    printf("its empty\n");
}

void unQueue2(Queue *ptr){
    if(isEmpty(ptr)!=false){
         ptr->arr[ptr->front++];
    }
    printf("its empty\n");
}

void reQueue(Queue *ptr){
    int val = delete(ptr);
    insert(ptr, val);
}

void reQueue2(Queue *ptr){
    int val = delete2(ptr);
    insert(ptr, val);
}

int main(){
    Queue q;
    int n, num;
    int front, rear;
    printf("enter the front and rear\n");
    scanf("%d%d", &front, &rear);
    q.front = front;
    q.rear = rear;
         do{
            printf("enter 1 to insert into queue\n");
            printf("Enter 2 to display queue\n");
            printf("Enter 3 to delete.\n");
            printf("enter 4 to unque\n");
            printf("enter 5 to requeue\n");
            printf("any other number to exit\n");       
            printf("enter choice\n");
            scanf("%d", &n);
            printf("Enter 1 to insert.\n");
        switch(n){

            case 1:
            printf("Enter the number to be inserted \n");
            scanf("%d",&num);
            if (rear == 0)  insert(&q, num);
            else insert2(&q, num);
            break;

            case 2:
            printf("Queue display \n");
            printf("%d\n%d", q.front, q.rear);
            if(rear == -1) queueDisplay2(&q, front);
            else queueDisplay(&q, front);
            break;

            case 3:
            printf("dequeue\n");
            if(q.front == -1) delete(&q);
            else delete2(&q);
            break;

            case 4:
            printf("unQueue\n");
            if(q.front == -1) unQueue(&q);
            else unQueue2(&q);
            break;

            case 5:
            printf("reQueue\n");
            if(q.front == -1) reQueue(&q);
            else reQueue2(&q);
            break;

            default:
            printf("invalid choice\n");
            break;
        }
    }while(n>=1 && n<=5);
    return 0;
}