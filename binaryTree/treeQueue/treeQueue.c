//
// Created by lonux on 2022/12/1.
//

#include "treeQueue.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//下面是实现
Queue* QueueCreate(){
    Queue* queue=(struct Queue*)malloc(sizeof(Queue));
    assert(queue);
    queue->size=DEFAULT_SIZE;
    queue->count=0;
    queue->front=0;
    queue->rear=0;
    queue->datastore=malloc(sizeof(void* )*DEFAULT_SIZE);
    queue->Insert=QueueInsert;
    queue->IsFull=QueueIsFull;
    queue->IsEmpty=QueueIsEmpty;
    queue->Delete=QueueDelete;
    queue->Front=QueueFront;
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
void QueueInsert(Queue* Queue , void* item ){
    if(QueueIsFull(Queue)){
        printf("队列已满");
        return;
    }
    Queue->datastore[Queue->rear]=item;
    Queue->rear=((Queue->rear+1)%Queue->size);
    Queue->count+=1;
}

//删除队首元素
TreeNode*  QueueDelete(Queue*Queue ){
    if(QueueIsEmpty(Queue)){
        printf("队列已空");
    }
    void* item=Queue->datastore[Queue->front];
    Queue->front=((Queue->front+1)%Queue->size);
    Queue->count-=1;
    return (TreeNode*)item;
}
//返回队首元素
TreeNode* QueueFront(Queue* Queue ){
    if(QueueIsEmpty(Queue)){
        printf("队列已空");
        return NULL;
    }
    return (TreeNode*)Queue->datastore[Queue->front];
}

