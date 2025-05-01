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

int main()
{
    Stack *s = initStack();
    printf("栈初始化成功，data=%d，next=%p\n", s->data, (void *)s->next);
    free(s);
    return 0;
}
