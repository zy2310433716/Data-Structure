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

// 进栈/压栈
int pushStack(Stack *s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("栈已经满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int main()
{
    // 定义栈
    Stack s;

    // 初始化栈
    initStack(&s);

    // 进栈/压栈
    pushStack(&s, 10);
    pushStack(&s, 20);
    pushStack(&s, 30);

    return 0;
}