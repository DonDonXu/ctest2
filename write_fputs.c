#include <stdio.h>

//写入一个字符串到文件
int main()
{
    FILE *fp = fopen("/home/donshu/ctest2/aaa","w");
    if(fp)
    {
        fputs("#include <stdio.h>\nint main()\n{\nprintf(\"hello world\\n\");\nreturn 0;\n}",fp);
        fputs("我是一个兵，来自老百姓",fp);
        fclose(fp);
    }
    return 0;
}