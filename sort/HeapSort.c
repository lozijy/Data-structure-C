//
// Created by lonux on 2022/12/10.
//
#include <stdio.h>
void HeapAdjust(int *L,int m,int n);
void HeapSort(int * L,int n);
void swap(int *L,int m,int n);
void print(int L[],int n);

int main(){
    int L1[]={ 5, 4, 3, 2, 1};
    int L2[]={2,3,1,7,4};
    HeapSort(L1,5);
    printf("L1:");
    print(L1,5);
    HeapSort(L2,5);
    printf("L2:");
    print(L2,5);
}

//L����,n���鳤��
void HeapSort(int  L[],int n){
    int i;
    int count=1;
    //��ʼ����
    for (i = n/2-1; i >=0 ; --i) {
        HeapAdjust(L,i,n-1);
    }
    //����������
    for (int j = n-1; j >=0 ; --j) {
        swap(L,0,j);
        HeapAdjust(L,0,j-1);
        printf("��%d�ν�������:\n",count++);
        print(L,n);
    }
}
//m��ʼ�±꣬nĩβ�±꣬��֤m��n������������
void HeapAdjust(int L[],int m,int n){
    int temp=L[m];
    int i;
    for (i = 2*(m+1)-1; i <= n; i=(i+1)*2-1) {
        if(i<n&&L[i]<L[i+1]){
            i++;
        }
        if(L[i]<temp){
            break;
        }
        L[m]=L[i];
        m=i;
    }
    L[m]=temp;
}
void print(int L[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d",L[i]);
    }
    printf("\n");

}
//m��n���±�
void swap(int L[],int m,int n){
    int temp=L[m];
    L[m]=L[n];
    L[n]=temp;
}


