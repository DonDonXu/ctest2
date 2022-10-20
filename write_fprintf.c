#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp = fopen("/home/donshu/ctest2/aaa","w");
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    while(strcmp(buf,"exit\n") != 0)
    {
       fprintf(fp, "%s", buf);
       fgets(buf, sizeof(buf), stdin); 
    }
    fclose(fp);
    return 0;
}