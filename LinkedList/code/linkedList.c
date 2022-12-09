#include "../include/linkedList.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdint.h>
Node* creatNode(int val){
    Node* node=(Node*) malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
}
linkedlist* creatlinkedlist(){
    linkedlist* list=(linkedlist*)malloc(sizeof(linkedlist));
    Node*head =NULL;
    list->size=0;
    list->find=&linkedfind;
    list->insert=&linkedinsert;
    list->remove=&linkedremove;
    list->print=linkedprint;
}//在索引为k的地方插入值为val的节点
void linkedinsert(struct linkedlist* list,int k,int val){
    assert(k<=list->size+1);
    assert(k>0);
    Node* node=creatNode(val);
    Node* tempnode=NULL;
    int cnt=1;
    //k是第一个
    if(list->size==0){
        list->head=node;
    }
    //k在中间和后面
    else {
        tempnode=list->head;
        while(cnt<k-1){
            tempnode=tempnode->next;
            cnt++;
        }
        node->next=tempnode->next;
        tempnode->next=node;
    }
    list->size++;
}
//删除索引为k的元素,并把值赋给item
void linkedremove(struct linkedlist* list,int k,int *item){
    assert(k<=list->size);
    assert(k>0);
    int cnt=1;
    Node* prenode=NULL;
    Node* tempnode=list->head;
    //k在头位置
    if(k==1){
        *item=tempnode->val;
        list->head=list->head->next;
        free(tempnode);
        tempnode=NULL;
    }
    //k在中间和后面
    else {
        while(cnt<k){
            prenode=tempnode;
            cnt++;
            tempnode=tempnode->next;
        }
        *item=tempnode->val;
        prenode->next=tempnode->next;
        free(  tempnode);
        tempnode=NULL;
        assert(!tempnode);
    }
    list->size--;
}
//查找索引为k的元素，把值赋给item
void linkedfind(struct linkedlist* list,int k,int* item){
    assert(k<=list->size);
    assert(k>0);
    int cnt=1;
    Node* tempnode=list->head;
    //大小为1
    if(list->size==1){
        *item=tempnode->val;
    }
    //k在中间和后面
    else {
        while(cnt<=k-1){
            cnt++;
            tempnode=tempnode->next;
        }
        *item=tempnode->val;
    }
}
//打印链表
void linkedprint(struct linkedlist* list){
    printf("\n");
    Node* node =list->head;
    for(int i =1;i<=list->size;i++){
        if(i<list->size){
        printf("%d -> ",node->val);
        }
        else{printf("%d",node->val);}
        node=node->next;
    }
    printf("\n");
    printf("链表当前长度为%d",list->size);
}