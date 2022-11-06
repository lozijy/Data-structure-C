#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
typedef struct Node{
    int val;
    struct Node * next;
}Node;

typedef struct linkedlist{
    struct Node* head;
    int size;
    void (*insert)(struct linkedlist *,int k,int val);//在第k个节点后插入值为val的节点
    void (*remove)(struct linkedlist *,int k,int *item);//删除第k个节点并把字段值赋给item
    void   (*find)(struct linkedlist *,int k,int *item);//存取:把第k个节点的字段值赋给item
    void (*print)(struct linkedlist *);//打印链表
}linkedlist;

Node* creatNode();
linkedlist* creatlinkedlist();//创建链表
void linkedinsert(struct linkedlist*,int,int);//插入元素
void linkedremove(struct linkedlist*,int,int*);//删除元素
void linkedfind(struct linkedlist*,int ,int *);
void linkedprint(struct linkedlist*);
#endif