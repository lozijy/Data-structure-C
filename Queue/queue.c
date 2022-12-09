#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "queue.h"
//下面是实现
Queue* QueueCreate(int size){
    Queue* queue=(struct Queue*)malloc(sizeof(Queue));
    assert(queue);
    queue->size=size;
    queue->count=0;
    queue->front=0;
    queue->rear=0;
    queue->datastore=(int *)malloc(sizeof(int )*size);
    queue->Insert=QueueInsert;
    queue->IsFull=QueueIsFull;
    queue->IsEmpty=QueueIsEmpty;
    queue->Delete=QueueDelete;
    queue->Front=QueueFront;
    queue->Print=QueuePrint;
    return queue;
}
//判断队列是否满
int QueueIsFull(Queue* Queue){
    assert(Queue !=NULL);
    return(Queue->count==Queue->size);
}
//判断队列是否为空
int QueueIsEmpty(Queue * Queue){
    assert(Queue !=NULL);
    return(!QueueIsFull(Queue)&&Queue->front==Queue->rear);
}
//插入
void QueueInsert(Queue* Queue , int item ){
    if(QueueIsFull(Queue)){
        printf("队列已满");
    }
    Queue->datastore[Queue->rear]=item;
    Queue->rear=((Queue->rear+1)%Queue->size);
    Queue->count+=1;
}

//删除队首元素
int   QueueDelete(Queue*Queue ){
    if(QueueIsEmpty(Queue)){
        printf("队列已空");
    }
    int item=Queue->datastore[Queue->front];
    Queue->front=((Queue->front+1)%Queue->size);
    Queue->count-=1;
    return item;
}
//返回队首元素
int QueueFront(Queue* Queue ){
    if(QueueIsEmpty(Queue)){
        printf("队列已空");
    }
    return Queue->datastore[Queue->front];
}
void QueuePrint(Queue* Queue) {
    if (Queue->count == 0) {
        return;
    }
    int temp=Queue->rear-1;

    if (Queue->front < Queue->rear) {
        for (int i = Queue->front; i < Queue->count - 2; i++) {
            printf("%d -> ", Queue->datastore[i]);
        }
        printf("%d\n",Queue->datastore[temp]);
    } else
    {
        if(Queue->rear!=0) {
            for (int i = Queue->front; i < Queue->size; i++) {
                printf("%d -> ", Queue->datastore[i]);
            }
            for (int i = 0; i < Queue->rear - 1; i++) {
                printf("%d -> ", Queue->datastore[i]);
            }
            printf("%d\n",Queue->datastore[temp]);
        } else
        {
            for (int i = Queue->front; i < Queue->size-1; i++) {
                printf("%d -> ", Queue->datastore[i]);
            }
            printf("%d\n",Queue->datastore[Queue->size-1]);
        }
    }
    printf("当前元素个数为%d",Queue->count);
}
