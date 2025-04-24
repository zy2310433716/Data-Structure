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

// 在指定位置插入
int insertNode(Node *l, int pos, ElemType e)
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

    // 创建新节点
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("malloc failed");
        return 0;
    }

    // 插入新节点
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return 1;
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

    // 插入节点
    insertNode(list, 2, 15);
    listNode(list);

    // 释放内存（防止内存泄漏）
    free(list);
    list = NULL;
    return 0;
}