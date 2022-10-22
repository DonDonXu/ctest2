#include <stdio.h>
#include <stdlib.h>

struct person_info{
    char name[30];
    char gender[5];
    int age;
};

//按照行读取
int main()
{
    FILE *fp = fopen("/opt/ctest2/aaa", "r");
    if(fp == NULL)
    {
        printf("the file is close!");
        return EXIT_FAILURE;
    }
    struct person_info *persons = (struct person_info *)malloc(10 * sizeof(struct person_info));
    int i = 0;
    // int z = fscanf(fp, "%s%s%d", &(persons + i)->name, &(persons + i)->gender, &(persons + i)->age);
    // printf("结果：%d\n", z);
    // rewind(fp);
    while(fscanf(fp, "%s%s%d", &(persons + i)->name, &(persons + i)->gender, &(persons + i)->age) == 3)
    {
 
        printf("第%d行", i);
        printf("%s,%s,%d\n", (persons + i)->name, (persons + i)->gender, (persons + i)->age);
        i = i + 1;
    }
    fclose(fp);
    for(i--;i >= 0;i --){
        printf("%s,%s,%d\n", (persons + i)->name, (persons + i)->gender, (persons + i)->age);
    }
    free(persons);
    return 0;
}