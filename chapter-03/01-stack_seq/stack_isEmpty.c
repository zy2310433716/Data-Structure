#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;
// 定义栈
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        printf("栈是空的\n");
        return 1;
    }
    else
    {
        printf("栈不是空的\n");
        return 0;
    }
}
int main()
{
    // 定义栈
    Stack s;

    // 初始化栈
    initStack(&s);

    // 判断栈是否为空
    isEmpty(&s);

    return 0;
}