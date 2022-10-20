#include <stdio.h>
#include <string.h>

//从终端输入数据到文件
int main()
{
    FILE *fp = fopen("/home/donshu/ctest2/aaa","w");
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    fprintf(fp, "%s", buf);
    fclose(fp);
    return 0;
}