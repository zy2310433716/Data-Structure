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

int main()
{
    seqlist list;
    initlist(&list);
    printf("初始化成功，目前的长度是%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));
    return 0;
}