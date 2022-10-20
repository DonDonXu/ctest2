#include <stdio.h>

//写入一个字符到文件
int main()
{
    FILE *fp = fopen("/home/donshu/ctest2/aaa","w");
    if(fp)
    {
        putc('c',fp);
        fclose(fp);
    }
    return 0;
}