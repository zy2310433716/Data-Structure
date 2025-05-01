#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
// 定义栈
typedef struct stack
{
    ElemType data;
    struct stack *next;
} Stack;

// 初始化栈
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    s->data = 0;
    s->next = NULL;
    return s;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    if (s->next == NULL)
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
    // 定义一个栈并初始化
    Stack *s = initStack();
    printf("栈初始化成功，data=%d，next=%p\n", s->data, (void *)s->next);

    // 判断栈是否为空
    isEmpty(s);
    free(s);
    return 0;
}
