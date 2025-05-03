#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 初始化队列
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (node == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("队列是空的\n");
        return 1;
    }
    else
    {
        printf("队列不是空的\n");
        return 0;
    }
}

// 入队
void equeue(Queue *q, ElemType e)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (node == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

// 出队
int dequeue(Queue *q, ElemType *e)
{
    if (q->front == q->rear)
    {
        printf("队列为空，无法出队\n");
        return 0;
    }
    QueueNode *tmpNode = q->front->next;
    *e = tmpNode->data;
    q->front->next = tmpNode->next;
    if (q->rear == tmpNode)
    {
        q->rear = q->front;
    }
    free(tmpNode);
    return 1;
}

// 获取队头元素
int getFront(Queue *q, ElemType *e)
{
    if (isEmpty(q))
    {
        printf("队列为空，无法获取队头元素\n");
        return 0;
    }
    *e = q->front->next->data;
    return 1;
}
int main()
{
    // 定义一个队列并初始化
    Queue *q = initQueue();

    // 判断队列是否为空
    isEmpty(q);

    // 入队
    equeue(q, 730);
    equeue(q, 740);
    equeue(q, 760);

    // 出队
    ElemType e = 0;
    dequeue(q, &e);
    printf("出队的元素是：%d\n", e);
    dequeue(q, &e);
    printf("出队的元素是：%d\n", e);

    // 获取队头元素
    getFront(q, &e);
    printf("队头元素是：%d\n", e);
    return 0;
}