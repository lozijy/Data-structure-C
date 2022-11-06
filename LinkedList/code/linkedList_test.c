#include "linkedList.c"

int main(){
    //test01
    linkedlist* list=creatlinkedlist();
    // //插入
    // linkedinsert(list,1,1);//插入头
    // linkedinsert(list,2,2);
    // linkedinsert(list,2,3);//插入中间
    // linkedinsert(list,4,4);
    // print(list);
    // int item=0;
    // //删除头
    // linkedremove(list,1,&item);//删除头
    // linkedremove(list,2,&item);//删除中间
    // print(list);

//test
    list->insert(list,1,1);
    list->print(list);

//test2
// linkedList_test.c:11:5: warning: attempt to free a non-heap object 'a' [-Wfree-nonheap-object]
//      free(&a);
//      ^~~~~~~~


//3
    // int a[]=(int*)malloc(sizeof(int)*20);?
    // int a[]={1,2,3};
    // a[0]=1;
    // printf("%d",a[0]);
    // void* p=&a;
    // free(p);
    // free(a);
    // printf("%d",a[0]);
// linkedList_test.c: In function 'main':
// linkedList_test.c:20:5: warning: attempt to free a non-heap object 'a' [-Wfree-nonheap-object]
//      free(a);
//      ^~~~~~~
// 11





}