#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILE_LINE_LEN 1024

int main(){
    char text[FILE_LINE_LEN];
    FILE *fp = fopen("/opt/ctest2/bbb", "r");
    
    int onex = fgets(text, FILE_LINE_LEN, fp);
    printf("读取结果：%d",onex);
    memset(text, 0x0, FILE_LINE_LEN);


    int twox = fgets(text, FILE_LINE_LEN, fp);
    int lenx = strlen(text);
    fseek(fp, -lenx, SEEK_END);
    printf("%s",text);
    printf("%d--%d\n", ftell(fp), strlen(text));
    memset(text, 0x0, FILE_LINE_LEN);
    sleep(1);










    fclose(fp);
}