#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef void(Tip_func)(void);
void tip_func1(void)
{
    printf("第一个锦囊\n");
}
void tip_func2(void)
{
    printf("第二个锦囊\n");
}

void tip_func3(void)
{
    printf("第三个锦囊\n");
}

typedef struct Tip
{
    char from[64];
    char to[64];
    Tip_func *tip_func;

} Tip;

Tip *create_Tip(char *from, char *to, Tip_func *tip)
{
    Tip *temp = (Tip *)malloc(sizeof(Tip));
    if (temp == NULL)
    {
        printf("error");
        return NULL;
    }
    strcpy(temp->from, from);
    strcpy(temp->to, to);
    temp->tip_func = tip;
    return temp;
}
void open_tips(Tip *tip)
{
    printf("这是%s写给%s的锦囊\n", tip->from, tip->to);
    tip->tip_func();
}
void destory_tips(Tip *tip)
{
    if (tip != NULL)
    {
        free(tip);
        tip = NULL;
    }
}
void test()
{
    printf("leave test");
}
int main()
{
    Tip *tip1 = create_Tip("as", "as", tip_func1);
    Tip *tip2 = create_Tip("刘", "未", tip_func2);
    Tip *tip3 = create_Tip("未刘", "刘未未", tip_func3);
    open_tips(tip1);
    open_tips(tip2);
    open_tips(tip3);
    destory_tips(tip1);
    destory_tips(tip2);
    destory_tips(tip3);
    // test();
    return 0;
}