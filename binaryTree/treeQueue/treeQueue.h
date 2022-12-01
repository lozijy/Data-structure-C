//
// Created by lonux on 2022/12/1.
//

#ifndef DATA_STRUCTURE_C_TREEQUEUE_H
#define DATA_STRUCTURE_C_TREEQUEUE_H
#define DEFAULT_SIZE 30
#include "../binaryTree/binaryTree.h"
typedef struct Queue{
    int size;
    int front;
    int count;
    int rear;
    void**  datastore;
    int (*IsFull)(struct Queue*);
    int (*IsEmpty)(struct Queue * Queue);
    void (*Insert)(struct Queue* Queue , void* item );
    TreeNode* (*Delete)(struct Queue*Queue  );
    TreeNode* (*Front)(struct Queue* Queue );
}Queue;

Queue* QueueCreate();
int QueueIsFull(Queue*);
int QueueIsEmpty(Queue * Queue);
void QueueInsert(Queue* Queue , void* item );
TreeNode* QueueDelete(Queue*Queue  );
TreeNode* QueueFront(Queue* Queue );

#endif //DATA_STRUCTURE_C_TREEQUEUE_H
