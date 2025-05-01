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

// 进栈
int pushStack(Stack *s, ElemType e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    if (p == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

// 出栈
int popStack(Stack *s, ElemType *e)
{
    if (s->next == NULL)
    {
        printf("空栈");
        return 0;
    }

    *e = s->next->data;
    Stack *q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}

int main()
{
    Stack *s = initStack();
    printf("栈初始化成功，data=%d，next=%p\n", s->data, (void *)s->next);

    // 进栈
    pushStack(s, 10);
    pushStack(s, 20);
    pushStack(s, 30);

    // 出栈
    ElemType e;
    popStack(s, &e);
    printf("出栈的元素为：%d\n", e);

    free(s);
    return 0;
}
