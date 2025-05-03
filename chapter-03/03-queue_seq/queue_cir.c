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

// 入队
int equeue(Queue *q, ElemType e)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        printf("队列已满\n");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

// 出队
int dequeue(Queue *q, ElemType *e)
{
    if (q->front == q->rear)
    {
        printf("队列是空的\n");
        return 0;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

// 获取队头元素
int getHead(Queue *q, ElemType *e)
{
    if (q->front == q->rear)
    {
        printf("队列是空的\n");
        return 0;
    }
    *e = q->data[q->front];
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
    equeue(&q, 730);
    equeue(&q, 740);
    equeue(&q, 760);

    // 出队
    ElemType e = 0;
    dequeue(&q, &e);
    printf("出队的元素是：%d\n", e);
    dequeue(&q, &e);
    printf("出队的元素是：%d\n", e);

    // 获取队头元素
    getHead(&q, &e);
    printf("队头元素是：%d\n", e);
    return 0;
}