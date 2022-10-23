#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/stat.h>

#define FILE_LINE_LEN 1024

long g_curr_offset = 0;
int32_t c_tail(const char *file);
int32_t c_tail(const char *file){
    FILE *fp = fopen(file, "r");
    if(!fp){
        printf("can\'t open file, file: %s\n", file);
        return -2;
    }
    char text[FILE_LINE_LEN];
    int eof_status;
    int tellx = 0;
    struct stat file_buf;
    //按行循环读取文件
    while (1){
        memset(text, 0x0, FILE_LINE_LEN);
        //按照行获取数据，保存到text
        fgets(text, FILE_LINE_LEN, fp);
        eof_status = feof(fp);
        stat(file, &file_buf);
        int file_size = file_buf.st_size;
        int lenx = strlen(text);
        int CICLE_X = 5;
        puts("循环跑步出来");
        //判断是否到文件结尾，读取到文件结尾，就等待新的数据写入；
        if(eof_status == 1){
            while(CICLE_X > 0){
                stat(file, &file_buf);
                if(file_buf.st_size > file_size){
                    if(text[lenx-1] == '\n'){
                        printf("%s", text);
                        fseek(fp, 0L, SEEK_END);
                        puts("xxxxxxxxxx");
                        CICLE_X = 0;
                    }else{
                        fseek(fp, -lenx, SEEK_END);
                        puts("yyyyyyyyyyy");
                        CICLE_X = 0;
                    }
                }else{
                    continue;
                    sleep(1);
                }
                // // printf("%d", file_buf.st_size);
                // // sleep(1);

                sleep(1);
            }
        }
        printf("%s", text);
        sleep(1);
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]){
    c_tail("/opt/ctest2/bbb");
    return 0;
}