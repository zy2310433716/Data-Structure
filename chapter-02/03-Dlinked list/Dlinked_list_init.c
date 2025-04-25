#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next, *prev;
} DNode;

// 初始化双链表
DNode *initList()
{
    DNode *head = (DNode *)malloc(sizeof(DNode));
    if (head == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}
int main()
{
    DNode *list = initList();

    return 0;
}