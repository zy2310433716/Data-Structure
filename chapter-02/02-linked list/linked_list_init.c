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

// 打印链表长度与占用字节
void printListStatus(Node *head)
{
    printf("==== 链表状态 ====\n");
    // 打印链表长度（假设头节点 data 存储有效节点数）
    printf("链表长度: %d\n", head->data);
    // 计算占用字节（头节点 + 有效节点数 × 单个节点大小）
    printf("占用字节: %zu\n", sizeof(Node) * (1 + head->data));
}

int main()
{
    Node *list = initList();
    printListStatus(list);
    // 释放内存（防止内存泄漏）
    free(list);
    list = NULL;
    return 0;
}