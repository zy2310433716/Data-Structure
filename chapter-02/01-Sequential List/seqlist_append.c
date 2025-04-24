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

int main()
{
    seqlist list;
    initlist(&list);

    // 添加元素
    appendElem(&list, 66);
    printf("目前的长度是%d\n", list.length);
    return 0;
}