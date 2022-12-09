#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PRINT_MIN_WIDTH 5
#define max(a,b) ((a)>(b)?(a):(b))
#define DEFAULT_SIZE 50

//二叉树的结点
typedef struct binaryTreeNode
{
    int val;
    struct binaryTreeNode* left;
    struct binaryTreeNode* right;
} TreeNode;

//新建二叉树结点
TreeNode* NewNode(int val){
    // if (!val){
    //     return NULL;
    // }
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//将树保存为二叉树形式
TreeNode* createTree(char* str){
    TreeNode* stk[10005]; int stk_top = 0;
    TreeNode* root = NewNode(0);
    TreeNode* curNode = root;
    for (int i=0;i<strlen(str);i++){
        if (str[i]=='('){
            curNode->left = NewNode(0);
            stk[stk_top] = curNode; stk_top++;
            curNode = curNode->left;
        }
        else if (str[i]==')'){
            stk_top--; curNode = stk[stk_top];
        }
        else{
            if (!curNode->val){
                curNode->val = str[i];
            }
            else{
                curNode->right = NewNode(str[i]);
                curNode = curNode->right;
            }
        }
    }
    return root;
}

//将森林保存为二叉树形式
TreeNode* createForest(char* str[], int n){
    TreeNode* trees[n];
    for (int i=0;i<n;i++){
        trees[i] = createTree(str[i]);
    }
    TreeNode* root = NewNode('0');
    TreeNode* tempNode = root;
    for (int i=0;i<n;i++){
        if (tempNode == root){
            tempNode->left = trees[i];
        }
        else{
            tempNode->right = trees[i];
        }
        tempNode = trees[i];
    }
    return root;
}

//以二叉树形式输出
void _BTreePrintBFS(TreeNode* root, int height);
int _getBTreeHeight(TreeNode* root, int depth);
void BTreePrint(TreeNode* root){
    printf("=========\n");
    printf("以二叉树形式输出\n");
    printf("=========\n");
    int height = _getBTreeHeight(root, 1);
    _BTreePrintBFS(root, height);
    printf("=========\n");
}

void _BTreePrintBFS(TreeNode* root, int height){
    int depth = 0;
    TreeNode** curNode = (TreeNode**)malloc(sizeof(TreeNode*)*10005); curNode[0]=root; int curNode_length = 1;
    TreeNode** nextNode = (TreeNode**)malloc(sizeof(TreeNode*)*10005); int nextNode_length = 0;
    while (depth<height){
        int width = PRINT_MIN_WIDTH * pow(2, height-depth-1) - 1;
        for (int j=0;j<width/2;j++){
            printf(" ");
        }
        for (int i=0;i<curNode_length;i++){
            TreeNode* cur = curNode[i];
            if (cur) {
                printf("%c", cur->val);
                nextNode[nextNode_length] = cur->left;nextNode_length++;
                nextNode[nextNode_length] = cur->right;nextNode_length++;
            }
            else{
                printf("_");
                nextNode[nextNode_length] = NULL;nextNode_length++;
                nextNode[nextNode_length] = NULL;nextNode_length++;
            }
            for (int j=0;j<width;j++){
                printf(" ");
            }
        }
        printf("\n");
        TreeNode** temp = curNode;
        curNode = nextNode; curNode_length = nextNode_length;
        nextNode = temp; nextNode_length = 0;
        depth++;
    }
    free(curNode);
    free(nextNode);
}

int _getBTreeHeight(TreeNode* root, int height){
    if (!root) {
        return height-1;
    }
    return max(_getBTreeHeight(root->left, height+1), _getBTreeHeight(root->right, height+1));
}

//以目录形式输出树
void TreePrintDFS(TreeNode* root, int depth);
void TreePrint(TreeNode* root){
    printf("=========\n");
    printf("以目录形式输出\n");
    printf("=========\n");
    TreePrintDFS(root, 0);
    printf("=========\n");
}

void TreePrintDFS(TreeNode* root, int depth){
    for (int i=0;i<PRINT_MIN_WIDTH*depth;i++){
        printf("-");
    }
    printf("%c\n", root->val);
    if (root->left){
        TreePrintDFS(root->left, depth+1);
    }
    if (root->right){
        TreePrintDFS(root->right, depth);
    }
}



//遍历相关

//森林的后序遍历,n记录当前遍历到第几棵树,c表示森林中总共有多少棵树
void PostTraversal(char* trees[],int n,int c){
    if(n==c){
        return;
    }
    char stk1[DEFAULT_SIZE];
    int top=0;
    int count=0;
    int mark[DEFAULT_SIZE];
    stk1[top]=trees[n][0];
    top++;

    for (int i = 1; i < strlen(trees[n]); ++i) {
        if(trees[n][i]=='('){
            mark[count++]=top;
        }
        else if(trees[n][i]==')'){
            for (int j = mark[count-1]; j < top; ++j) {
                printf("%c ", stk1[j]);
            }
            printf("%c ",stk1[mark[count-1]-1]);
            top=mark[count-1]-1;
            count--;

        }else{
            stk1[top++]=trees[n][i];
        }

    }
    PostTraversal(trees,n+1,c);
}

int main(void){
    char* trees[] = {"A(BC(DE)F)", "Q(WE)", "F(H(IGK)J)"};
    PostTraversal(trees,0,3);
    return 0;
}