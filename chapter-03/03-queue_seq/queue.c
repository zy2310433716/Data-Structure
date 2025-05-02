#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
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

// 如果队尾满了，调整队列
// 队尾满了，调整队列
int queueFull(Queue *Q)
{
    if (Q->front > 0)
    {
        int step = Q->front;
        for (int i = Q->front; i < Q->rear; i++)
        {
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else
    {
        printf("队列真的满了\n");
        return 0;
    }
}

// 入队
int equeue(Queue *q, ElemType e)
{
    if (q->rear >= MAXSIZE)
    {
        if (queueFull(q) == 0)
        {
            return 0;
        }
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

// 出队
int dequeue(Queue *Q, ElemType *e)
{
    if (Q->front == Q->rear) // 队列为空
    {
        printf("队列是空的\n");
        return 0; // 出队失败
    }

    *e = Q->data[Q->front]; // 提取队头元素
    Q->front++;             // 队头指针后移
    return 1;               // 出队成功
}

// 获取队头元素
int getHead(Queue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}

int main()
{
    // 定义一个队列并初始化
    Queue q;
    initQueue(&q);

    // 判断队列是否为空
    isEmpty(&q);

    // 入队
    equeue(&q, 10);
    equeue(&q, 20);
    equeue(&q, 30);

    // 出队
    ElemType e;
    dequeue(&q, &e);
    printf("出队的元素是：%d\n", e);
    dequeue(&q, &e);
    printf("出队的元素是：%d\n", e);

    // 获取队头元素
    getHead(&q, &e);
    printf("队头元素是：%d\n", e);
    return 0;
}