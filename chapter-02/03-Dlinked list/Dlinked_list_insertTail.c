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

// 获取尾节点（用于快速定位链表末端）
DNode *get_tail(DNode *l)
{
    DNode *p = l;           // 从头节点开始
    while (p->next != NULL) // 核心逻辑：持续向后查找
    {
        p = p->next; // 直到找到next为NULL的节点
    }
    return p; // 返回尾节点指针
}

// 尾插法
DNode *insertTail(DNode *tail, ElemType e)
{
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if (p == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}

int main()
{
    // 创建双链表并初始化
    DNode *list = initList();

    // 获取尾节点
    DNode *tail = get_tail(list);

    // 尾插法
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);

    // 遍历
    listNode(list);
    return 0;
}