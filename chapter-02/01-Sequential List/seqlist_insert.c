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

// 遍历线性表
void traverse(seqlist *l)
{
    for (int i = 0; i < l->length; i++)
    {
        printf("%d\n", l->data[i]);
    }
}

// 插入元素
int insertElem(seqlist *l, int pos, ElemType e)
{
    // 判断顺序表是否已满
    if (l->length >= MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }

    // 判断插入位置是否合法
    if (pos < 1 || pos > l->length + 1)
    {
        printf("插入位置错误\n");
        return 0;
    }

    // 插入数据
    if (pos <= l->length)
    {
        for (int i = l->length; i >= pos - 1; i--)
        {
            l->data[i + 1] = l->data[i];
        }
        l->data[pos - 1] = e;
        l->length++;
    }
    return 1;
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

    // 遍历顺序表
    traverse(&list);

    // 在第二个位置插入540
    insertElem(&list, 2, 540);

    // 查看插入后的结果
    traverse(&list);
    return 0;
}