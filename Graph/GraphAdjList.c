//
// Created by lonux on 2022/12/8.
//
#include <stdio.h>
#include <stdlib.h>
#include "Queue/queue.h"
#define MAXVEX 50
#define STACK_DEFAULT_SIZE 50
//�߱�ڵ�
typedef struct EdgeNode{
    int adjvex;//�ڽӵ��򣬼�¼�±�
    int weight;//��¼Ȩֵ
    struct EdgeNode *next;
}EdgeNode;
//�����ڵ�
typedef struct VertexNode{
    int mark;
    EdgeNode* firstEdge;
}VertexNode;
//ͼ
typedef struct {
    VertexNode adjList[MAXVEX];
    int numVertexes,numEdges;
    int type;
}GraphAdjList;

//�����ڽӾ���ͼ��v_numΪ�����Ŀ��typeΪ�Ƿ�Ϊ����ͼ��relations�����Ԫ��ϵ(��int��ʾ��ţ�����СΪ1)��nΪ��Ԫ��ϵ��.
GraphAdjList *CreateAlGraph(int v_num ,int type,int relations[][3],int n){
    GraphAdjList *G= (GraphAdjList *)malloc(sizeof (GraphAdjList));
    G->type=type;
    G->numVertexes=v_num;
    G->numEdges=n;

    //�����
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            G->adjList[relations[i][j]-1].firstEdge = NULL;
            G->adjList[relations[i][j]-1].mark=0;
        }
    }
    //�����
    EdgeNode * e;
    for (int i = 0; i < n; ++i) {
        e= (EdgeNode *)malloc(sizeof (EdgeNode));
        e->adjvex=relations[i][1]-1;
        e->weight=relations[i][2];
        e->next=G->adjList[relations[i][0]-1].firstEdge;
        G->adjList[relations[i][0]-1].firstEdge=e;
    }
    //���������ͼ���һ������
    if(type==0) {
        for (int i = 0; i < n; ++i) {    int relations[][3] = {
        {1, 2, 3},
        {2, 3, 4},
        {2, 4, 7},
        {2, 5,10},
        {3, 6, 2},
        {4, 3, 10},
        {5, 6, 7}
    };
    int n = 7;
    int v_num = 6;
            e= (EdgeNode *)malloc(sizeof (EdgeNode));
            e->adjvex=relations[i][0]-1;
            e->weight=relations[i][2];
            e->next=G->adjList[relations[i][1]-1].firstEdge;
            G->adjList[relations[i][1]].firstEdge=e;
        }
    }
    return G;
}

//�ǵݹ��������
int DFS(GraphAdjList * G,int a){
    if(a>G->numVertexes){
        printf("*[ERROR] The graph has no Vertex%d...\n", a);
        return -1;
    }
    printf("������ȱ���:\n");
    int mark[G->numVertexes];
    int stk[STACK_DEFAULT_SIZE];
    int top=0;
    int cur=a-1;
    for (int i = 0; i < G->numVertexes; ++i) {
        mark[i]=0;
    }
    stk[top++]=cur;
    printf("%d " ,cur+1);
    mark[cur]=1;
    while(top!=0){
        cur=stk[top-1];
        top--;
        EdgeNode * e=G->adjList[cur].firstEdge;
//        printf(" %d -> adjevex%d\n",cur,e->adjvex+1);
        while(e!=NULL){
//            printf("%d",mark[e->adjvex]);
            if(mark[e->adjvex]!=1){
                stk[top++]=cur;
                stk[top++]=e->adjvex;
                mark[e->adjvex]=1;
                printf("%d ",e->adjvex+1);
                break;
            }
            e=e->next;
        }

    }

}
//�ǵݹ�����������
int BFS(GraphAdjList * G,int a){
    if(a>G->numVertexes){
        printf("*[ERROR] The graph has no Vertex%d...\n", a);
        return -1;
    }
    printf("������ȱ���:\n");

    Queue* queue=QueueCreate(STACK_DEFAULT_SIZE);
    int mark[G->numVertexes];
    for (int i = 0; i < G->numVertexes; ++i) {
        mark[i]=0;
    }
    queue->Insert(queue,a-1);
    mark[a-1]=1;
    while (queue->IsEmpty(queue)!=1){
        int cur=queue->Delete(queue);
        printf("%d ",cur+1);
        EdgeNode * e=G->adjList[cur].firstEdge;
        while(e!=NULL) {
            if (mark[e->adjvex] != 1) {
                queue->Insert(queue, e->adjvex);
                mark[e->adjvex] = 1;
            }
            e = e->next;
        }
    }



}
int print(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; ++i) {
        printf("��%d :", i + 1);
        EdgeNode *e = G->adjList[i].firstEdge;
        while (e != NULL) {
            printf("%d ", e->adjvex+1);
            e = e->next;
        }
        printf("NULL");
        printf("\n");
    }
}
int main(){
//    int relations[][3] = {
//            {1, 2, 3},
//            {1,3,1},
//            {2,3,1}
//    };
//    int n = 3;
//    int v_num = 3;

    int relations[][3] = {
            {1, 2, 3},
            {2, 3, 4},
            {2, 4, 7},
            {2, 5,10},
            {3, 6, 2},
            {4, 3, 10},
            {5, 6, 7}
    };
    int n = 7;
    int v_num = 6;
    GraphAdjList *G = CreateAlGraph(v_num,1, relations, n);
    print(G);
    DFS(G,1);
    BFS(G,1);
}