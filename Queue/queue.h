#ifndef _QUQUE_H_
#define _QUEUE_H_
typedef struct Queue{
    int size;
    int front;
    int count;
    int rear;
    int*  datastore;
    int (*IsFull)(struct Queue*);
    int (*IsEmpty)(struct Queue * Queue);
    void (*Insert)(struct Queue* Queue , int item );
    int (*Delete)(struct Queue*Queue  );
    int (*Front)(struct Queue* Queue );
    void (*Print)(struct Queue* Queue);
}Queue;

Queue* QueueCreate();
int QueueIsFull(Queue*);
int QueueIsEmpty(Queue * Queue);
void QueueInsert(Queue* Queue , int item );
int QueueDelete(Queue*Queue  );
int QueueFront(Queue* Queue );
void QueuePrint(Queue* Queue);//打印

#endif
