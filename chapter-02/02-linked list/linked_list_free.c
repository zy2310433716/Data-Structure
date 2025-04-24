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
int getLength(Node *l)
{
    if (l == NULL)
    {
        printf("警告：尝试访问已销毁的链表\n");
        return 0;
    }

    int len = 0;
    Node *p = l->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
// 释放链表
void freeList(Node *l)
{
    Node *p = l->next;
    Node *q;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    l->next = NULL;
}

int main()
{
    Node *list = initList();
    // 头插法插入数据
    insertHead(list, 10);
    insertHead(list, 20);

    // 查看链表长度

    // 释放内存（防止内存泄漏）
    printf("释放前链表长度：%d\n", getLength(list));
    freeList(list);
    free(list);
    list = NULL;
    printf("释放后链表长度：%d\n", getLength(list));
    return 0;
}