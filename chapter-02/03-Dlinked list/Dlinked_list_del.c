
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

// 头插法
int insertHead(DNode *l, ElemType e)
{
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if (p == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    p->prev = l;
    p->next = l->next;
    if (l->next != NULL)
    {
        l->next->prev = p;
    }
    l->next = p;
    return 1;
}

// 遍历
void listNode(DNode *l)
{
    DNode *p = l->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// 删除节点
int deleteNode(DNode *l, int pos)
{
    DNode *p = l;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return 0;
        }
    }

    if (p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    DNode *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

int main()
{
    // 创建双链表并初始化
    DNode *list = initList();

    // 头插法插入节点
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);

    // 遍历
    listNode(list);

    // 删除
    deleteNode(list, 2);

    // 再次遍历
    listNode(list);
    return 0;
}