#include <stdio.h>
      #include <errno.h>
      
      void fscanfTest(FILE* fp) {
        char c1, c2, s1[100], s2[100];
        int d;
      
        // 第一部分：fscanf对空格的处理
        printf("the content of file is:\n");
        printf("hello<\\b>world<\\b><\\b>666lucky<\\n>");
        printf("\n\n");
      
        // %s不会跳过后面的空格
        fscanf(fp, "%s", s1);
        printf("%s!\n", s1);  // hello!
      
        // %s会跳过前面的一个空格
        rewind(fp);   // 将光标移回文件开头
        fscanf(fp, "%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // hello! world!
      
        // %*s会从文件流中读入，但是不会将值赋予变量（*的作用）
        rewind(fp);
        fscanf(fp, "%*s%s", s1);
        printf("%s!\n", s1);  // world!
      
        // %s会跳过前面的多个空格
        rewind(fp);
        fscanf(fp, "%*s%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // world! 666lucky!
      
        // %c不会跳过空格
        rewind(fp);
        fscanf(fp, "%*s%c", &c1);
        printf("%c!\n", c1); // " !"
      
        // format str中的一个空格表示如果文件流接下来有连续空格，都跳过
        rewind(fp);
        fscanf(fp, "%*s%*s %c", &c1);
        printf("%c!\n", c1);          // "6!"
        rewind(fp);
        fscanf(fp, "%*s%*s%*d%c", &c1);
        printf("%c!\n", c1);          // "l!" 
        rewind(fp);
        fscanf(fp, "%*s%*s%*d %c", &c2);   // 注意这里format str中的空格没起作用，是因为666和lucky之间没有空白符
        printf("%c!\n", c2);          // "l!"
        rewind(fp);
        fscanf(fp, "%*s%*s%*d%s", s1);
        printf("%s!\n", s1);          // "lucky!" 
        rewind(fp);
        fscanf(fp, "%*s%*s%*d %s", s2);
        printf("%s!\n", s2);          // "lucky!"
      
        // format str中的多个连续空格和一个空格的效果是一样的
        rewind(fp);
        fscanf(fp, "%*s %c", &c1);
        printf("%c!\n", c1); // "w!"
        rewind(fp);
        fscanf(fp, "%*s  %c", &c2);
        printf("%c!\n", c2); // "w!"
      
        // 第二部分：fscanf对制表符的处理
        printf("the content of file is:\n");
        printf("hello<\\t>world<\\t><\\t>666lucky<\\n>");
        printf("\n\n");
      
        // %s不会跳过后面的制表符
        fscanf(fp, "%s", s1);
        printf("%s!\n", s1);  // hello!
      
        // %s会跳过前面的一个制表符
        rewind(fp);
        fscanf(fp, "%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // hello! world!
      
        // %s会跳过前面的多个制表符
        rewind(fp);
        fscanf(fp, "%*s%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // world! 666lucky!
      
        // %c不会跳过制表符
        rewind(fp);
        fscanf(fp, "%*s%c", &c1);
        printf("%c!\n", c1); // "<\\t>!"
      
        // format str中的一个制表符表示如果文件流接下来有连续制表符，都跳过
        rewind(fp);
        fscanf(fp, "%*s%*s\t%c", &c1);
        printf("%c!\n", c1);          // "6!"
        rewind(fp);
        fscanf(fp, "%*s%*s%*d%c", &c1);
        printf("%c!\n", c1);          // "l!" 
        rewind(fp);
        fscanf(fp, "%*s%*s%*d\t%c", &c2);
        printf("%c!\n", c2);          // "l!"
        rewind(fp);
        fscanf(fp, "%*s%*s%*d%s", s1);
        printf("%s!\n", s1);          // "lucky!" 
        rewind(fp);
        fscanf(fp, "%*s%*s%*d\t%s", s2);
        printf("%s!\n", s2);          // "lucky!"
      
        // format str中的多个连续制表符和一个制表符的效果是一样的
        rewind(fp);
        fscanf(fp, "%*s\t%c", &c1);
        printf("%c!\n", c1); // "w!"
        rewind(fp);
        fscanf(fp, "%*s\t\t%c", &c2);
        printf("%c!\n", c2); // "w!"
      
        // 第三部分：fscanf对换行符的处理
        printf("the content of file is:\n");
        printf("hello<\\n>world<\\n><\\n>666lucky<\\n>");
        printf("\n\n");
      
        // %s不会跳过后面的换行符
        fscanf(fp, "%s", s1);
        printf("%s!\n", s1);  // hello!
      
        // %s会跳过前面的一个换行符
        rewind(fp);
        fscanf(fp, "%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // hello! world!
      
        // %s会跳过前面的多个换行符
        rewind(fp);
        fscanf(fp, "%*s%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // world! 666lucky!
      
        // %c不会跳过换行符
        rewind(fp);
        fscanf(fp, "%*s%c", &c1);
        printf("%c!\n", c1); // "<\\n>!"
      
        // format str中的一个换行符表示如果文件流接下来有连续换行符，都跳过
        rewind(fp);
        fscanf(fp, "%*s%*s\n%c", &c1);
        printf("%c!\n", c1);          // "6!"
        rewind(fp);
        fscanf(fp, "%*s%*s%*d%c", &c1);
        printf("%c!\n", c1);          // "l!" 
        rewind(fp);
        fscanf(fp, "%*s%*s%*d\n%c", &c2);
        printf("%c!\n", c2);          // "l!"
        rewind(fp);
        fscanf(fp, "%*s%*s%*d%s", s1);
        printf("%s!\n", s1);          // "lucky!" 
        rewind(fp);
        fscanf(fp, "%*s%*s%*d\n%s", s2);
        printf("%s!\n", s2);          // "lucky!"
      
        // format str中的多个连续换行符和一个换行符的效果是一样的
        rewind(fp);
        fscanf(fp, "%*s\n%c", &c1);
        printf("%c!\n", c1); // "w!"
        rewind(fp);
        fscanf(fp, "%*s\n\n%c", &c2);
        printf("%c!\n", c2); // "w!"
      
        // 第四部分：当空格、制表符以及换行符混杂时fscanf的处理
        printf("the content of file is:\n");
        printf("hello<\\b><\\t><\\n>world<\\t><\\b><\\n>666lucky<\\n>");
        printf("\n\n");
      
        // %s会跳过连在一起的空格、制表符和换行符
        fscanf(fp, "%s%s", s2, s1);
        printf("%s! %s!\n", s2, s1);  // hello! world!
      
        // 当作为空白符时，format str中的空格、制表符以及换行符是一样的，可以相互替代！
        rewind(fp);
        fscanf(fp, "%*s %c", &c1);
        printf("%c!\n", c1);  // "w!"
        rewind(fp);
        fscanf(fp, "%*s\t%c", &c2);
        printf("%c!\n", c2);  // "w!"
        rewind(fp);
        fscanf(fp, "%*s\n%c", &c1);
        printf("%c!\n", c1);  // "w!"
      
        // 第五部分：[]符号在format str中的应用
        printf("the content of file is:\n");
        printf("hello<\\b><\\t><\\n>world<\\b><\\t>666lucky<\\n>");
        printf("\n\n");
      
        // [el]表示只读取'e'或者'l'这个字符，[0-9]表示只读取0-9这10个数字字符
        // %[]之后的域都不起作用了，不会读取文件流。
        // test#1: %c%[]s可以正常工作
        // output#1: h! ell!
        errno = 0;
        d = fscanf(fp, "%c%[el]s", &c1, s1);
        if (d == 2) printf("%c! %s!\n", c1, s1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#2: %[]s后面的%c没有正常读取
        // output#2: d = 2
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%c%[el]s%c", &c2, s2, &c1);
        if (d == 3) printf("%c! %s! %c!\n", c2, s2, c1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#3: %[]s后面的%s没有正常读取
        // output#3: d = 2
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%c%[el]s%s", &c1, s1, s2);
        if (d == 3) printf("%c! %s! %s!\n", c1, s1, s2);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#4: 再次运行fscanf函数就可以继续读取文件流
        // output#4: o! world!
        errno = 0;
        d = fscanf(fp, "%c%s", &c2, s2);
        if (d == 2) printf("%c! %s!\n", c2, s2);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
      
        // [^el]表示不读取'e'也不读取'l'这个字符，[^0-9]表示不读取0-9的数字字符
        // %[^]之后的域都不起作用了，不会读取文件流。
        // test#5: %c%[^]s可以正常工作，注意下面的%[^w]s这个域读取了空格、制表符以及换行符。
        // output#5: h! ello<\\b><\\t><\\n>!
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%c%[^w]s", &c1, s1);
        if (d == 2) printf("%c! %s!\n", c1, s1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#6: %[^]s后面的%s没有正常读取
        // output#6: d = 2
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%c%[^w]s%s", &c2, s2, s1);
        if (d == 3) printf("%c! %s! %s!\n", c2, s2, s1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#7: 再次运行fscanf函数就可以继续读取文件流
        // output#7: w! orld!
        errno = 0;
        d = fscanf(fp, "%c%s", &c1, s1);
        if (d == 2) printf("%c! %s!\n", c1, s1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#8: %[^\n]s可以一直读取到行末尾，哪怕遇到空格或者制表符。
        // output#8: h! ello<\\b><\\t>!
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%c%[^\n]s", &c2, s2);
        if (d == 2) printf("%c! %s!\n", c2, s2);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
        // test#9: %[^ ]s不会读取空格，但是会读取制表符和换行符
        // output#9: <\\t><\\n>world!
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%*s%*c%[^ ]s", s1);
        if (d == 1) printf("%s!\n", s1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }  
        // test#10: %[^\t]s不会读取制表符，但是会读取空格和换行符
        // output#10: <\\n>world<\\b>!
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%*s%*c%*c%[^\t]s", s2);
        if (d == 1) printf("%s!\n", s2);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        } 
        // test#11: %[^]s不会跳过前面的空白符
        // output#11: <\\b><\\t><\\n>wo!
        errno = 0;
        rewind(fp);
        d = fscanf(fp, "%*s%[^r]s", s1);
        if (d == 1) printf("%s!\n", s1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
      
        // 第六部分：出错的情况
        // 从第五部分 test#2 以及 test#3 的例子中可以看出，fscanf的返回值表示能够正确赋值的域的个数。如果出错，fscanf返回EOF。
        // 怎样才算出错？如果还没有任何一个域匹配成功或者任何一个匹配失败发生之前，就达到了文件流末尾，就算出错；或者读取文件流出错。就这两种情况。
        // 即使所有域都不匹配，但只要没到达文件流末尾并且读取文件流过程中没有发生错误，就不算出错，errno就是0。此时，fscanf返回0。
        printf("the content of file is:\n");
        printf("hello");
        printf("\n\n");
      
        // test#1: 此时的%c发生匹配失败，所以返回值为0。
        // output#1: d = 0
        errno = 0;
        d = fscanf(fp, "%*s%c", &c1);
        if (d == 1) printf("%c!\n", c1);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }   
        // test#2: 继续读取，已经到达文件流末尾，返回EOF。
        // output#2: d = -1
        errno = 0;
        d = fscanf(fp, "%c", &c2);
        if (d == 1) printf("%c!\n", c2);
        else {
          printf("d = %d\n", d);
          if (errno != 0) perror("fscanf");
          else printf("Error: no matching characters!\n");
        }
      }
      
      int main(int argc, char* argv[]) {
        FILE *fp;
        if (argc < 2) {
          printf("Usage: %s <filename>\n", argv[0]);
          return 1;
        }
        if ((fp = fopen(argv[1], "r")) == NULL) {
          printf("Error: cannot open file\n");
          return 1;
        }
        fscanfTest(fp);
        fclose(fp);
        return 0;
      }