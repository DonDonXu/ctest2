#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

//获取文件的大小 
int get_file_size(int f)
{
  struct stat st;
  fstat(f, &st);
  return st.st_size;
}

int get_file_size_stat(){
    struct stat st;
    stat("/opt/ctest2/bbb", &st);
    return st.st_size;
}

int get_file_size_lstat(){
    struct stat st;
    lstat("/opt/ctest2/bbb", &st);
    return st.st_size;
}
int main(void)
{
 int fd = open("/opt/ctest2/bbb",O_RDWR);
 int size , size_stat, size_lstat;
 if(fd < 0)
 {
 printf("open fair!\n");
 return -1 ;
 }
 size = get_file_size(fd) ;
 size_stat = get_file_size_stat();
  size_lstat = get_file_size_lstat();
 printf("size:%d\n",size);
 printf("stat_size:%d\n",size_stat);
  printf("lstat_size:%d\n",size_lstat);
 return 0 ; 
}