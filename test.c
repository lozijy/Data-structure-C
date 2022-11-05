#include<stdio.h>
int* max(int*,int*);
int* min(int*,int*);
int* add(int *,int *);
int* (*exec[])(int*a,int *b)={
    &max,
    &min
};
int* max(int*a,int*b){
    return *a>*b?a:b;
}
int* min(int*a,int*b){
    return *a>*b?b:a;
}
int* add(int *,int *);
int main(){
    int a=1;
    int b=2;
    printf("%d",*(exec[0](&a,&b)));
    printf("%d",*(exec[1](&a,&b)));
}