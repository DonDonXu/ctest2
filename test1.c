#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp;
    fp = fopen("/home/donshu/ctest2/aaa", "r");
    fclose(fp);
    return 0;
}