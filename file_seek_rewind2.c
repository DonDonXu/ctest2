#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILE_LINE_LEN 1024

void read_offset(char *file){
    long offset_buff;
    FILE *fp = fopen(file, "r");
    if (!fp) {  
        printf("cant open file, file: %s\n", file);  
        return -2;
    } 
    fscanf(fp, "%ld", &offset_buff);
    fclose(fp);
}

void write_offset(char *file, long offset){
    FILE *fp = fopen(file, "w");
    if (!fp) {  
        printf("cant open file, file: %s\n", file);
        return -2;
    }
    fprintf(fp, "%ld", offset);
    fclose(fp);
}


int main(){
    char text[FILE_LINE_LEN];
    FILE *fp = fopen("/home/donshu/ctest2/bbb", "r");
    int position = 0;
    while(1){
        memset(text, 0x0, FILE_LINE_LEN);
        fgets(text, FILE_LINE_LEN, fp);
        position = ftell(fp);
        write_offset("/tmp/aaa", position);
        if(feof(fp) == 1){
            fseek(fp, position, SEEK_SET);
        };
        sleep(1);
        printf("%s", text);
    }
    puts("程序结束了");
    fclose(fp);
}