#include<stdio.h>
#include<stdbool.h>
#define SIZE 100

typedef struct{
    int size;
    int front;
    int rear;
    int arr[SIZE];
}Queue;

bool isFull(Queue *ptr){
    if(ptr->rear == SIZE-1) return true;
    return false;
}

bool isFull1(Queue *ptr){
    if(ptr->rear == SIZE) return true;
    return false;
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
   if(isFull(ptr)!=false){  
      ptr->arr[++ptr->rear] = val;
   }else{
    printf("its full\n");
   }
}

void insert2(Queue *ptr, int val){
    if(isFull1(ptr)!=false){
        ptr->arr[ptr->rear++] = val;
    }else{
        printf("its full\n");
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

void queueDisplay(Queue *ptr){
    for(int i=ptr->front+1; i<=ptr->rear; i++){
            printf("the val is %d\n", ptr->arr[i]);
        }
}

void queueDisplay2(Queue *ptr){
     for(int i=ptr->front;i<ptr->rear;i++){
            printf("the val is %d\n", ptr->arr[i]);
        }
}

int main(){
    Queue q;
    int n, num;
    printf("Enter 1 to insert.\n");
    printf("Enter 2 to delete.\n");
    printf("Enter 3 to display stack");
    printf("any other number to exit\n");
    printf("enter the front and rear\n");
    scanf("%d%d", &q.front, &q.rear);
      do{
        printf("enter choice\n");
        scanf("%d", &n);
        switch(n){

            case 1:
            printf("Enter the number to be added to queue\n");
            scanf("%d", &num);
            if(q.rear == 0) insert2(&q, num);
            else insert(&q, num);
            break;

            case 2:
            if(q.front == -1){
                printf("%d is sucessfully deleted\n", delete2(&q));
            }else{
                delete(&q);
            }
            break;

            case 3:
             if(q.front == -1){
                reQueue(&q);
            }else{
                reQueue2(&q);
            }

            case 4:
                if(q.front == -1){
                unQueue(&q);
            }else{
                unQueue2(&q);
            }

            case 5:
            if(q.rear == -1) queueDisplay(&q);
            else queueDisplay2(&q);
            break;

            default:
            printf("invalid chaoice\n");
            break;
        }
    }while(n<=5);

    return 0;
}