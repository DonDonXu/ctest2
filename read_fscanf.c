#include <stdio.h>
#include <stdlib.h>

//按照行读取
int main()
{
    FILE *fp = fopen("/home/donshu/ctest2/aaa", "r");
    if(fp == NULL)
    {
        printf("the file is close!");
        return EXIT_FAILURE;
    }
    char str1[200], str2[200], str3[200];
    int status;
    while(fscanf(fp, "%s %s %s", str1, str2, str3) == 3)
    {
        printf("%s %s %s status = %d\n", str1, str2, str3, status);
    }
    fclose(fp);
    return 0;
}