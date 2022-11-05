#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
typedef struct Node{
    int val;
    struct Node * next;
}Node;
typedef struct linkedlist{
    Node node;
    struct Node* head;
    void (*insert)(struct linkedlist *,struct Node*node,int val);//插入
    void (*remove)(struct linkedlist *,int val);//删除元素
    struct Node*   (*find)(struct linkedlist *,int val);//查找
}linkedlist;
linkedlist* creatlinkedlist();//创建链表
void linkedinsert(struct linkedlist*,struct Node*,int val);//插入元素
void linkedremove(struct linkedlist*,int);//删除元素
struct Node* linkedfind();//查找元素
#endif