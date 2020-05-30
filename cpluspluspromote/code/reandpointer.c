#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
typedef struct Teacher
{
    int id;
    char name[64];
} Teacher;
void get_Mem(Teacher **p)
{
    Teacher *temp = NULL;
    temp= (Teacher *)malloc(sizeof(Teacher));
    temp->id=10;
    strcpy(temp->name,"liuwei");
    *p=temp;
}
int main()
{
    Teacher *s=NULL;
    get_Mem(&s);
    printf("%d\n",s->id);
    printf("%s\n",s->name);
    return 0;
}