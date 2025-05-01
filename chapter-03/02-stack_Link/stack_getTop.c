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

// 获取栈顶元素
int getTop(Stack *s, ElemType *e)
{
    if (s->next == NULL)
    {
        printf("空栈\n");
        return 0;
    }
    *e = s->next->data;
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

    // 获取栈顶元素
    ElemType e;
    getTop(s, &e);
    printf("栈顶元素为：%d\n", e);

    free(s);
    return 0;
}
