#include <stdio.h>
#include <stdlib.h>

struct person_info{
    char name[30];
    char gender[5];
    int age;
} dong;

//按照行读取
int main()
{
    FILE *fp = fopen("/opt/ctest2/aaa", "r");
    if(fp == NULL)
    {
        printf("the file is close!");
        return EXIT_FAILURE;
    }
    int z = fscanf(fp, "%s%s%d", &dong.name, &dong.gender, &dong.age);
    printf("结果：%d", z);
    printf("%s,%s,%d", dong.name, dong.gender, dong.age);
    fclose(fp);
    return 0;
}