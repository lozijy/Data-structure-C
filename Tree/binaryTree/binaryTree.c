#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PRINT_MIN_WIDTH 5
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct binaryTreeNode
{
    int val;
    struct binaryTreeNode* left;
    struct binaryTreeNode* right;
} TreeNode;


//新建二叉树结点
TreeNode* NewNode(int val){
    if (!val){
        return NULL;
    }
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//创建二叉树
TreeNode* _BTreeCreateDFS(int* A, int length, int n);
TreeNode* BTreeCreate(int* A, int length){
    return _BTreeCreateDFS(A, length, 1);
}

TreeNode* _BTreeCreateDFS(int* A, int length, int n){
    if (n>length){
        return NULL;
    }
    TreeNode* node = NewNode(A[n-1]); //n-1才是对应元素下标

    if (n*2<=length){
        node->left = _BTreeCreateDFS(A, length, n*2);
    }
    else if(node){
        node->left = NULL;
    }
    if (n*2+1<=length){
        node->right = _BTreeCreateDFS(A, length, n*2+1);
    }
    else if(node){
        node->right = NULL;
    }
    return node;
}

//输出二叉树
void _BTreePrintBFS(TreeNode* root, int height);
int _getBTreeHeight(TreeNode* root, int depth);
void BTreePrint(TreeNode* root){
    printf("=========\n");
    printf("Tree\n");
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
                printf("%d", cur->val);
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


//先序遍历
void preOrderTraveral(TreeNode* root){
    if (!root) {
        return;
    }
    //对结点的操作，这里仅进行标准输出
    {
        printf("%d ", root->val);
    }
    preOrderTraveral(root->left);
    preOrderTraveral(root->right);
}

//中序遍历
void inOrderTraveral(TreeNode* root){
    if (!root) {
        return;
    }
    inOrderTraveral(root->left);
    //对结点的操作，这里仅进行标准输出
    {
        printf("%d ", root->val);
    }
    inOrderTraveral(root->right);
}

//后序遍历
void postOrderTraveral(TreeNode* root){
    if (!root) {
        return;
    }
    postOrderTraveral(root->left);
    postOrderTraveral(root->right);
    //对结点的操作，这里仅进行标准输出
    {
        printf("%d ", root->val);
    }
}


//搜索指定值结点的父结点
TreeNode* searchParent(TreeNode* tree, TreeNode* node){
    if (!node){
        return NULL;
    }
    TreeNode* stk[10005] = {tree}; int stk_top=1;
    while (stk_top){
        TreeNode* temp = stk[stk_top-1]; stk_top--;
        if (temp->left == node || temp->right == node){
            return temp;
        }
        else{
            if (temp->left){
                stk[stk_top] = temp->left; stk_top++;
            }
            if (temp->right){
                stk[stk_top] = temp->right; stk_top++;
            }
        }
    }
    return NULL;
}


//搜索指定值的结点(使用前序遍历，只查找一个满足要求的结点)
void _searchNodeDFS(TreeNode* root, int value, TreeNode** ans);
TreeNode* searchNode(TreeNode* tree, int value){
    TreeNode* ans = NULL;
    _searchNodeDFS(tree, value, &ans);
    return ans;
}

void _searchNodeDFS(TreeNode* root, int value, TreeNode** ans){
    if (!root) {
        return;
    }
    {
        if (root->val == value){
            *ans = root;
            return;
        }
    }
    _searchNodeDFS(root->left, value, ans);
    _searchNodeDFS(root->right, value, ans);
}


//删除指定结点
void _freeNode(TreeNode* node);
void deleteNode(TreeNode* root, TreeNode* node){
    TreeNode* parent = searchParent(root, node);
    if (root==node){
        _freeNode(node);
        return;
    }
    if (!parent){
        return;
    }
    else{
        if (parent->left == node){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }
    _freeNode(node);
}

void _freeNode(TreeNode* node){
    if (node->left){
        _freeNode(node->left);
    }
    if (node->right){
        _freeNode(node->right);
    }
    if (!node->left && !node->right){
        free(node);
    }
}