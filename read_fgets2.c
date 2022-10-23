#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>

#define FILE_LINE_LEN 1024  
  
long g_curr_offset = 0;  
  
int32_t c_tail(const char *file);
int32_t c_tail(const char *file){  
    FILE *fp = fopen(file, "r");  
    if (!fp) {  
        printf("cant open file, file: %s\n", file);  
        return -2;   
    }     
  
    fseek(fp, g_curr_offset, SEEK_SET);  
  
    char text[FILE_LINE_LEN];  
    uint32_t len;  
    while(!feof(fp)) {  
        sleep(1);
        memset(text, 0x0, FILE_LINE_LEN);  
        fgets(text, FILE_LINE_LEN, fp);  
        len = strlen(text);  
        if (len == 0 || text[len - 1] != '\n') continue;  
        text[len - 1] = 0;  
        g_curr_offset += len;  
        
        printf("%s\n", text);
    }     
  
    fclose(fp);  
  
    return 0;  
}  

// void read_offset(char *file){
//     // long offset_buff;
//     FILE *fp = fopen(file, "r");  
//     if (!fp) {  
//         printf("cant open file, file: %s\n", file);  
//         return -2;   
//     } 
//     fscanf(fp, "%ld", &g_curr_offset);
//     fclose(fp);
// }
// void write_offset(char *file, long offset){
//     FILE *fp = fopen(file, "w");  
//     if (!fp) {  
//         printf("cant open file, file: %s\n", file);  
//         return -2;   
//     }
//     fprintf(fp, "%ld", offset);
//     fclose(fp);
// }
int main(int argc, char *argv[])  
{  
    while(1){
        sleep(1);
        c_tail("/opt/ctest2/bbb");  
    }

    return 0;  
}  