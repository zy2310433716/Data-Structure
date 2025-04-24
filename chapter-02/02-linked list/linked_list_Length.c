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

// 获取链表长度
int listNode(Node *l)
{
    Node *p = l->next;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

int main()
{
    Node *list = initList();
    // 头插法插入数据
    insertHead(list, 10);
    insertHead(list, 20);

    // 查看链表长度
    int r = listNode(list);
    // 释放内存（防止内存泄漏）
    printf("当前链表的长度为：%d\n", r);
    free(list);
    list = NULL;
    return 0;
}