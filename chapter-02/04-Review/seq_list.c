#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

// 顺序表定义
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} seqList;

// 顺序表初始化
void initList(seqList *l)
{
    l->length = 0;
}

// 尾部添加元素
int appendElem(seqList *l, ElemType e)
{
    if (l->length >= MAXSIZE)
    {
        printf("顺序表已满");
        return 0;
    }
    l->data[l->length] = e;
    l->length++;
    return 1;
}

// 顺序表遍历
void printList(seqList *l)
{
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

// 插入元素
int insertElem(seqList *l, int pos, ElemType e)
{
    if (l->length >= MAXSIZE)
    {
        printf("顺序表已满");
        return 0;
    }

    if (pos < 1 || pos > l->length + 1)
    {
        printf("插入位置错误\n");
        return 0;
    }

    if (pos <= l->length)
    {
        for (int i = l->length - 1; i >= pos - 1; i--)
        {
            l->data[i + 1] = l->data[i];
        }
        l->data[pos - 1] = e;
        l->length++;
    }
    return 1;
}

// 删除元素
int deleteElem(seqList *l, int pos, ElemType *e)
{
    if (l->length == 0)
    {
        printf("空表");
        return 0;
    }

    if (pos < 1 || pos > l->length)
    {
        printf("删除数据位置有误\n");
        return 0;
    }

    *e = l->data[pos - 1];

    if (pos < l->length)
    {
        for (int i = pos; i < l->length; i++)
        {
            l->data[i - 1] = l->data[i];
        }
    }
    l->length--;
    return 1;
}
// 查找指定元素的位置
int findElem(seqList *l, ElemType e)
{
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
}
int main()
{
    // 声明一个顺序表并初始化
    seqList list;
    initList(&list);
    printf("初始化成功，目前的长度是%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));

    // 尾部添加元素
    appendElem(&list, 525);
    appendElem(&list, 530);
    appendElem(&list, 730);

    // 遍历
    printList(&list);

    // 插入元素
    insertElem(&list, 2, 528);

    // 再次遍历
    printList(&list);

    // 删除元素
    ElemType delData;
    deleteElem(&list, 2, &delData);

    // 再次遍历
    printf("被删除的数据为：%d\n", delData);
    printList(&list);

    // 查找元素位序
    printf("这个元素的位序是：%d", findElem(&list, 730));

    return 0;
}