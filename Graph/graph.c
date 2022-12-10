//
// Created by lonux on 2022/12/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph_Matrix{
    int v_num;
    int type;
    int** matrix;
} Graph;

//创建邻接矩阵图，v_num为点的数目，type为是否为有向图，relations代表二元关系(用int表示编号，且最小为1)，n为二元关系数.
Graph* createGraphMatrix(int v_num, int type, int relations[][3], int n){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    int** matrix = (int**)malloc(sizeof(int*)*(v_num));
    graph->v_num = v_num;
    graph->type = type;
    graph->matrix = matrix;
    //初始化二维数组
    for (int i=0;i<v_num;i++){
        matrix[i] = (int*)malloc(sizeof(int)*(v_num));
        for (int j=0;j<v_num;j++){
            matrix[i][j] = 0;
        }
    }
    //遍历二元关系并进行计数
    if (type){
        //有向图
        //不考虑0权边，同向平行边，自环
        for (int i=0;i<n;i++){
            matrix[relations[i][0]-1][relations[i][1]-1] = relations[i][2];
        }
    }
    else{
        //无向图
        //不考虑0权边，平行边，自环
        for (int i=0;i<n;i++){
            matrix[relations[i][0]-1][relations[i][1]-1] = relations[i][2];
            matrix[relations[i][1]-1][relations[i][0]-1] = relations[i][2];
        }
    }
    return graph;
}

//返回图中指定边的权值，a为起点，b为起点.如不存在该边，则返回0
int getEdgeWeight(Graph* graph, int a, int b){
    if (a > graph->v_num){
        printf("*[ERROR] The graph has no Vertex%d...\n", a);
        return 0;
    }
    if (b > graph->v_num){
        printf("*[ERROR] The graph has no Vertex%d...\n", b);
        return 0;
    }
    int weight = graph->matrix[a-1][b-1];
    if (a==b){
        printf("*[ERROR] Vertex%d can't connect to itself...\n", a);
    }
    else if (!weight){
        printf("*[ERROR] There is no edge connecting Vertex%d to Vertex%d...\n", a, b);
    }
    return weight;
}

//返回图中某顶点的第一个邻接顶点，a为顶点.如果不存在该顶点或其不存在邻接顶点，则返回0.
int getFirstNeighbor(Graph* graph, int a){
    if (a > graph->v_num){
        printf("*[ERROR] The graph has no Vertex%d...\n", a);
        return 0;
    }
    for (int i=0;i<graph->v_num;i++){
        if (graph->matrix[a-1][i]){
            return i+1;
        }
    }
    printf("*[ERROR] The Vertex%d has no neighbor...\n", a);
    return 0;
}

//返回图中顶点b对于顶点a的下一个邻接顶点的序号.如果不存在该顶点或其不存在下一邻接顶点，则返回0.（如顶点a与顶点b、c邻接，则“顶点b对于顶点a的下一个邻接顶点”为顶点c）
int getNextNeighbor(Graph* graph, int a, int b){
    if (a > graph->v_num){
        printf("*[ERROR] The graph has no Vertex%d...\n", a);
        return 0;
    }
    if (b > graph->v_num){
        printf("*[ERROR] The graph has no Vertex%d...\n", b);
        return 0;
    }
    if (!graph->matrix[a-1][b-1]){
        printf("*[warning] There is no edge connecting Vertex%d to Vertex%d...\n", a, b);
    }
    for (int i=b;i<graph->v_num;i++){
        if (graph->matrix[a-1][i]) {
            return i+1;
        }
    }
    printf("*[ERROR] The Vertex%d has no next neighbor...\n", a);
    return 0;
}



int main(void){
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

    Graph* digraph = createGraphMatrix(v_num, 1, relations, n); //有向图
    Graph* undigraph = createGraphMatrix(v_num, 0, relations, n); //无向图
    int a, b;

    printf("===========\n");

    a = 2;
    b = 3;
    int target_weight;
    target_weight = getEdgeWeight(digraph, a, b);
    printf("[Digraph] The weight of edge between Vertex%d and Vertex%d is %d.\n", a, b, target_weight);
    target_weight = getEdgeWeight(undigraph, a, b);
    printf("[Undigraph] The weight of edge between Vertex%d and Vertex%d is %d.\n", a, b, target_weight);

    printf("===========\n");

    a = 3;
    int first_vertex;
    first_vertex = getFirstNeighbor(digraph, a);
    printf("[Digraph] The first neighbor of Vertex%d is Vertex%d.\n", a, first_vertex);
    first_vertex = getFirstNeighbor(undigraph, a);
    printf("[Undigraph] The first neighbor of Vertex%d is Vertex%d.\n", a, first_vertex);

    printf("===========\n");

    a = 3;
    b = 4;
    int next_vertex;
    next_vertex = getNextNeighbor(digraph, a, b);
    printf("[Digraph] The next neighbor of Vertex%d after Vertex%d is Vertex%d.\n", a, b, next_vertex);
    next_vertex = getNextNeighbor(undigraph, a, b);
    printf("[Undigraph] The next neighbor of Vertex%d after Vertex%d is Vertex%d.\n", a, b, next_vertex);

    printf("===========\n");


}