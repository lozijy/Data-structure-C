#include "linkedList.h"
#include<stdlib.h>
linkedlist* creatlinkedlist(){
    linkedlist* list=(linkedlist*)malloc(sizeof(linkedlist));
    Node*head =NULL;
    list->find=linkedfind;
    list->insert=linkedfind;
    list->remove=linkedremove;
}//创建链表
void linkedinsert(struct linkedlist*,struct Node*,int val){
    
}//插入元素
void linkedremove(struct linkedlist*,int);//删除元素
struct Node* linkedfind();//查找元素