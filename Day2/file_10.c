// file_10.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
   unlink("c.txt"); // delete file
   

   printf("mypid : %d\n", getpid()); //process id
   
   int fd = open("log", O_RDWR | O_CREATE | O_TRUNC, 0666);
 
   getchar();
   unlink("log"); // 이때는 dentry만 지움, inode는 살아있음
                  // 그래서 ls 에서는 안보임, 작업은 계속하고 있고, 프로그램 종료되면 사라짐

   getchar();
   close(fd);

}
