#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILE_LINE_LEN 1024

int main(){
    char text[FILE_LINE_LEN];
    FILE *fp = fopen("/home/donshu/ctest2/bbb", "r");


    memset(text, 0x0, FILE_LINE_LEN);
    fgets(text, FILE_LINE_LEN, fp);
    int onex = feof(fp);
    printf("%s",text);
    printf("读取fgets值：%d\n",onex);
    memset(text, 0x0, FILE_LINE_LEN);


    fgets(text, FILE_LINE_LEN, fp);
    int twox = feof(fp);
    printf("%s",text);
    printf("读取fgets值：%d\n",twox);
    int lenx = strlen(text);
//------------------------------------------------
    puts("----------------------");
    memset(text, 0x0, FILE_LINE_LEN);
    fgets(text, FILE_LINE_LEN, fp);
    int fourx = feof(fp);
    printf("%s",text);
    printf("读取fgets值：%d\n",fourx);
    int lenxx = strlen(text);
    printf("字符串长度：%d", lenxx);
    puts("----------------------"); 
//------------------------------------------------
    fseek(fp, 0, SEEK_SET);
    memset(text, 0x0, FILE_LINE_LEN);

    fgets(text, FILE_LINE_LEN, fp);
    int threex = feof(fp);
    printf("%s",text);
    printf("读取fgets值：%d\n",threex);
    sleep(1);










    fclose(fp);
}