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

// 获取尾节点
Node *get_tail(Node *l)
{
    Node *p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

int main()
{
    Node *list = initList();
    Node *tail = get_tail(list);
    // 尾插法插入数据
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);

    // 遍历
    listNode(list);

    // 释放内存（防止内存泄漏）
    free(list);
    list = NULL;
    return 0;
}