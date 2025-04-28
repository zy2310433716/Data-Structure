#include <stdio.h>
#include <stdlib.h>
// 定义元素类型
typedef int ElemType;

// 定义链表结构体
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

// 链表初始化
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

// 头插法插入元素
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

// 遍历链表
void traverseList(Node *l)
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
    if (p == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

// 指定位置插入
int insertList(Node *l, int pos, ElemType e)
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
    Node *q = (Node *)malloc(sizeof(Node));
    if (q == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

// 指定位置删除
int delList(Node *l, int pos)
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
        printf("删除的位置有误\n");
        return 0;
    }

    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

// 获取链表长度
int listLength(Node *l)
{
    if (l == NULL)
    {
        printf("警告：尝试访问已销毁的链表\n");
        return 0;
    }
    Node *p = l->next;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 释放链表
int freeList(Node *l)
{
    if (l == NULL)
    {
        printf("访问错误");
        return 0;
    }

    Node *p = l->next;
    Node *temp;

    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(l);
    return 1;
}
int main()
{
    // 定义一个链表并初始化
    Node *list = initList();

    // 头插法
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    printf("当前链表的长度为：%d\n", listLength(list));
    // 遍历链表
    traverseList(list);

    // 尾插法
    Node *tail = get_tail(list);
    tail = insertTail(tail, 730);
    tail = insertTail(tail, 740);
    tail = insertTail(tail, 760);
    traverseList(list);

    // 指定位置插入
    insertList(list, 5, 735);
    traverseList(list);

    // 指定位置删除节点
    delList(list, 5);
    traverseList(list);
    printf("当前链表的长度为：%d\n", listLength(list));

    // 释放链表
    if (freeList(list) == 1)
    {
        printf("链表释放成功！\n");
        list = NULL;
    }
    else
    {
        printf("链表释放失败！\n");
    }
    return 0;
}