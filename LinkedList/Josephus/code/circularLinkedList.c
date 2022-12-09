#include<stdio.h>
#include<stdlib.h>

//单个结点
typedef struct Node
{
    int val; //节点值
    struct Node* next; //下一个节点
} Node;

//简单的循环链表，只保留了部分功能
//为了操作方便，多提供了一些参数，又只用cur表示当前指针
typedef struct circularLinkedList
{
    int size; //链表的原长度
    int count; //链表元素个数
    Node* cur; //循环链表所指当前元素

    void (*print)(struct circularLinkedList*);
    void (*simplePrint)(struct circularLinkedList*);
    int (*remove)(struct circularLinkedList*);
    void (*move)(struct circularLinkedList*, int);

} circularLinkedList;


circularLinkedList* createCircularLinkedList(int);
void circularLinkedListPrint(circularLinkedList*);
void circularLinkedListSimplePrint(circularLinkedList*);
int circularLinkedListRemove(circularLinkedList*);
void circularLinkedListCurMove(circularLinkedList*, int);



//创建新节点
Node* createNode(int value){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = value;
    new->next = NULL;
    return new;
}

//创建新的简单循环链表
circularLinkedList* createCircularLinkedList(int size){
    circularLinkedList* newList = (circularLinkedList*)malloc(sizeof(circularLinkedList));
    newList->print = circularLinkedListPrint;
    newList->simplePrint = circularLinkedListSimplePrint;
    newList->remove = circularLinkedListRemove;
    newList->move = circularLinkedListCurMove;

    Node* headNode = NULL;
    Node* tempNode = NULL;
    if (!size){
        //size为0的特殊情况，返回一个空链表
        newList->size = size;
        newList->count = size;
        newList->cur = NULL;
        return newList;
    }
    for (int i=1;i<=size;i++){
        Node* newNode = createNode(i); //编号从1开始
        if (!headNode) {
            headNode = newNode;
            tempNode = newNode;
            }
        else{
            tempNode->next = newNode;
            tempNode = newNode;
        }
    }
    tempNode->next = headNode; //循环

    newList->size = size;
    newList->count = size;
    //考虑到特殊情况，为一开始循环提供一个虚节点，且虚节点不计入元素个数
    Node* startNode = createNode(0);
    startNode->next = headNode;
    newList->cur = startNode;
    return newList;
}

//输出循环链表
void circularLinkedListPrint(circularLinkedList* list){
    if (!list->count){
        printf("The circular linked list is empty.\n");
        return;
    }
    else{
        int origin = list->cur->val;
        Node* tempNode = list->cur->next;
        if (!origin){
            //跳过开始给予的虚节点
            origin = list->cur->next->val;
            tempNode = list->cur->next->next;
            printf("The circular linked list is:\n(%d) -> %d",list->cur->val, origin);
        }
        else{
            printf("The circular linked list is:\n%d",origin);
        }
        //由于循环链表中每个值不同，可以使用临时节点值是否与cur节点值相同作为结束依据
        while (tempNode->val!=origin){
            printf(" -> %d", tempNode->val);
            tempNode = tempNode->next;
        }
    }
    printf("\nNode count: %d, List size: %d\n", list->count, list->size);
}

//简洁输出循环链表
void circularLinkedListSimplePrint(circularLinkedList* list){
    if (!list->count){
        printf("The linked list: EMPTY\n");
        return;
    }
    else{
        int origin = list->cur->val;
        Node* tempNode = list->cur->next;
        if (!origin){
            //跳过开始给予的虚节点
            origin = list->cur->next->val;
            tempNode = list->cur->next->next;
            printf("The linked list: (%d) -> %d",list->cur->val, origin);
        }
        else{
            printf("The linked list: %d",origin);
        }
        //由于循环链表中每个值不同，可以使用临时节点值是否与cur节点值相同作为结束依据
        while (tempNode->val!=origin){
            printf(" -> %d", tempNode->val);
            tempNode = tempNode->next;
        }
    }
}

//删除链表中下一位置的元素并返回其值
int circularLinkedListRemove(circularLinkedList* list){
    if (list->count<=1){
        //迎合问题条件，元素个数小于等于1时就不进行删除
        printf("Can't remove next node since the linked list has no more than one node.");
        return 0;
    }
    else if (!list->cur->val){
        //当为当前节点为虚节点时，且此时元素个数大于1
        Node* lastNode = list->cur->next;
        Node* nextNode = list->cur->next->next;
        int origin = list->cur->next->val;
        while(lastNode->next->val!=origin){
            lastNode = lastNode->next;
        }
        free(list->cur->next); //所删除的节点
        lastNode->next = nextNode;
        list->cur->next = nextNode;
        list->count--;
        return origin;
    }
    else{
        Node* tempNode = list->cur->next;
        list->cur->next = tempNode->next;
        list->count--;
        int removeValue = tempNode->val;
        free(tempNode); //释放无用内存
        return removeValue;
    }
}

//将链表的cur指针向后移动step次
void circularLinkedListCurMove(circularLinkedList* list, int step){
    if (!list->count){
        printf("Can't move the 'cur' because the linked list is empty.");
        return;
    }
    for (int i=0;i<step;i++){
        list->cur = list->cur->next;
    }
}

// 去掉注释，直接运行该文件可进行测试
// int main(void){
//     circularLinkedList* list = createCircularLinkedList(2); //特殊取值可为1
//     list->print(list);

//     list->remove(list);
//     list->print(list);

//     list->move(list, 0); //特殊值可取0，此时cur指针不移动
//     list->print(list);

//     return 0;
// }