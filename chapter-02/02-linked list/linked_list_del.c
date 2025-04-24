#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

// 初始化链表
Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

// 头插法
int insertHead(Node *l, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    p->next = l->next;
    l->next = p;
    return 1;
}

// 遍历
void listNode(Node *l)
{
    Node *p = l->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 删除节点
int deleteNode(Node *l, int pos)
{
    Node *p = l;
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
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

int main()
{
    Node *list = initList();
    // 头插法插入数据
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);

    // 遍历
    listNode(list);

    // 删除节点
    deleteNode(list, 2);

    // 遍历
    listNode(list);
    // 释放内存（防止内存泄漏）
    free(list);
    list = NULL;
    return 0;
}