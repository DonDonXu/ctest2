#include <stdio.h>
#include <stdlib.h>

//按指定的缓存大小读取文件
int main()
{
    FILE *fp = fopen("/home/donshu/ctest2/aaa","r");
    if(fp == NULL)
        return EXIT_FAILURE;
    char temp[1024];
    // fgets(temp,sizeof(temp),fp);
    while(!feof(fp))
    {
        fgets(temp,sizeof(temp),fp);
        printf("%s",temp);
    }
    fclose(fp);
    return 0;
}