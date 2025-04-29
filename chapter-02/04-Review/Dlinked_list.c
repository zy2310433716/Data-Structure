#include <stdio.h>
#include <stdlib.h>

// 定义元素类型
typedef int ElemType;

// 定义双链表
typedef struct dnode
{
    ElemType data;
    struct dnode *next;
    struct dnode *prev;

} Dnode;

// 初始化双链表
Dnode *initList()
{
    Dnode *head = (Dnode *)malloc(sizeof(Dnode));
    if (head == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    head->data = 0;
    head->next = 0;
    head->prev = 0;
    return head;
}

// 头插法
int insertHead(Dnode *l, ElemType e)
{
    Dnode *p = (Dnode *)malloc(sizeof(Dnode));
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

// 遍历链表
void traverseList(Dnode *l)
{
    Dnode *p = l->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取尾节点
Dnode *get_tail(Dnode *l)
{
    Dnode *p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 尾插法
Dnode *insertTail(Dnode *tail, ElemType e)
{
    Dnode *p = (Dnode *)malloc(sizeof(Dnode));
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

// 指定位置插入
int insertNode(Dnode *l, int pos, ElemType e)
{
    Dnode *p = l;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return 0;
        }
    }

    Dnode *q = (Dnode *)malloc(sizeof(Dnode));
    if (q == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    q->data = e;
    q->prev = p;
    q->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = q;
    }
    p->next = q;
    return 1;
}

// 删除节点
int deleteNode(Dnode *l, int pos)
{
    Dnode *p = l;
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
    Dnode *q = p->next;
    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prev = p;
    }
    free(q);
    return 1;
}

// 获取链表长度
int listLength(Dnode *l)
{
    if (l == NULL)
    {
        printf("警告：尝试访问已销毁的链表\n");
        return 0;
    }
    Dnode *p = l->next;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 释放链表
int freeList(Dnode *l)
{
    if (l == NULL)
    {
        printf("访问错误");
        return 0;
    }

    Dnode *p = l->next;
    Dnode *temp;

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
    // 创建链表
    Dnode *list = initList();

    // 头插法
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);

    // 遍历
    traverseList(list);
    printf("当前链表的长度为：%d\n", listLength(list));

    // 尾插法
    Dnode *tail = get_tail(list); // 获取尾结点
    tail = insertTail(tail, 730);
    tail = insertTail(tail, 750);
    tail = insertTail(tail, 760);
    traverseList(list);
    printf("当前链表的长度为：%d\n", listLength(list));

    // 指定位置插入
    insertNode(list, 5, 740);
    traverseList(list);

    // 删除节点
    deleteNode(list, 6);
    traverseList(list);

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