#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

// 顺序表定义
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} seqlist;

// 顺序表初始化
void initlist(seqlist *l)
{
    l->length = 0;
}

// 尾部添加元素
int appendElem(seqlist *l, ElemType e)
{
    if (l->length >= MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }

    l->data[l->length] = e;
    l->length++;
    return 1;
}

int findElem(seqlist *l, ElemType e)
{
    // 判断表是否为空
    if (l->length == 0)
    {
        printf("空表\n");
        return 0;
    }

    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    // 定义
    seqlist list;

    // 初始化
    initlist(&list);

    // 添加元素
    appendElem(&list, 530);
    appendElem(&list, 730);
    appendElem(&list, 740);

    // 查找指定元素
    printf("%d\n", findElem(&list, 740));
    return 0;
}