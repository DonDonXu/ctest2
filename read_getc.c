#include <stdio.h>
#include <stdlib.h>

//一个字符，一个字符读写文件；

int main(int argc, char *argv[]){

    FILE *fp;
    fp = fopen("/home/donshu/ctest2/aaa", "r");
    if(fp != NULL){
        char c;
        while(1){
            c = getc(fp);
            if(c == EOF) break;
            printf("%c", c);
        }
    }else{
        printf("打开文件失败；\n");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return 0;
}