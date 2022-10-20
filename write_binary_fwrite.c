#include <stdio.h>
void writeFile()
{
    FILE *p = fopen("b.txt", "w");
    char buf = 'a';
    int i;
    for(i = 0; i < 10 ; i++)
    {
        fwrite(&buf, 1, 1, p);
        buf++;
    }
    fclose(p);
}
int main()
{
    writeFile();
    return 0;
}