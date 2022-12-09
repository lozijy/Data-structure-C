#include "./circularLinkedList.c"

int main(void){
    int n=0,m=0,s=0;
    printf("Please input the value of n,m,s in order:\n");
    scanf("%d,%d,%d", &n, &m, &s);
    if (!(n && m && s)){
        printf("You have inputed wrong value.Each of the numbers can't be valued 0.\nPlease try again.\n");
    }

    printf("======Ready======\n");
    //共有 n 个人参与，依次编号
    circularLinkedList* mainList = createCircularLinkedList(n);
    //从第 s 个人开始计数
    mainList->move(mainList, s-1);
    mainList->print(mainList);
    printf("======Start======\n");
    while(mainList->count>1){
        //每 m 个人出局一个
        mainList->move(mainList, m-1);
        int value = mainList->remove(mainList);
        printf("Member %d failed. ", value);
        mainList->simplePrint(mainList);
        printf("\n");
    }
    printf("=====Result======\n");
    mainList->print(mainList);
    if (!mainList->cur->val){
        //当cur仍为虚节点时前进一步
        mainList->move(mainList, 1);
    }
    printf("The winner is Member %d!", mainList->cur->val);
}