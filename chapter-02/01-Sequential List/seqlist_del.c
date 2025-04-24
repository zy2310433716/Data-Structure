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
void traverse(seqlist *l)
{
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

// 删除元素
int deleteElem(seqlist *l, int pos, ElemType *e)
{
    // 判断表是否为空
    if (l->length == 0)
    {
        printf("空表\n");
        return 0;
    }

    // 判断位置合法性
    if (pos < 1 || pos > l->length)
    {
        printf("删除数据位置有误\n");
        return 0;
    }

    // 记录要删除的数据
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

    // 记录将要删除的数据
    ElemType delData;

    // 删除元素
    deleteElem(&list, 2, &delData);

    // 打印被删除的数据，并再次遍历顺序表
    printf("被删除的数据为：%d\n", delData);
    traverse(&list);
    return 0;
}