#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 16
typedef struct Stack
{
    int size;
    int top;
    int *datastore;

    int (*isEmpty)(struct Stack *stack);
    void (*push)(struct Stack *stack, int item);
    int (*pop)(struct Stack *stack);
    int (*peek)(struct Stack *stack);
    void (*print)(struct Stack *stack);
} Stack;

Stack *StackCreate();
int StackIsEmpty(Stack *stack);
void StackPush(Stack *stack, int item);
int StackPop(Stack *stack);
int StackPeek(Stack *stack);
void StackPrint(Stack *stack);


Stack *StackCreate()
{
    Stack *stack = (struct Stack *)malloc(sizeof(Stack));
    assert(stack);
    stack->top = 0;
    stack->datastore = (int *)malloc(sizeof(int) * SIZE);
    stack->isEmpty = &StackIsEmpty;
    stack->push = &StackPush;
    stack->pop = &StackPop;
    stack->peek = &StackPeek;
    stack->print = &StackPrint;
    return stack;
}


int StackIsEmpty(Stack *stack)
{
    assert(stack != NULL);
    return (stack->top == 0);
}

void StackPush(Stack *stack, int item)
{
    if (stack->top == SIZE)
    {
        printf("栈满");
    }
    stack->datastore[stack->top] = item;
    stack->top = ((stack->top + 1));
}

int StackPop(Stack *stack)
{
    if (StackIsEmpty(stack))
    {
        printf("栈空");
    }
    stack->top--;
    int item = stack->datastore[stack->top];

    return item;
}


int StackPeek(Stack *stack)
{
    if (StackIsEmpty(stack))
    {
        printf("栈空");
    }
    return stack->datastore[stack->top-1];
}

void StackPrint(Stack *stack)
{
    if (stack->top == 0)
    {
        return;
    }
    for (int i = 0; i < stack->top-1; i++)
    {
        printf("%d -> ", stack->datastore[i]);
    }
    printf("%d", stack->datastore[stack->top-1]);
    printf(" %d", stack->datastore[stack->top]);
}
int main()
{
    Stack *stack = StackCreate();
    stack->push(stack, 1);
    stack->push(stack, 2);
    stack->push(stack, 3);
    printf("%d\n", stack->pop(stack));
    printf("%d\n", stack->peek(stack));
    stack->print(stack);
}