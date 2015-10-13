//file_9.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> // for umask

int main()
{
    //1. bug
    //int fd = open("c.txt", O_RDWR | O_CREATE | O_TRUNC );

    // 2. 
    unlink("c.txt"); // file delete

    int old_mask = umask(0); //-> umask값을 0으로 지정 원래는 2
    printf("old mask : %d\n", old_mask); // 2 (000 000 010)

    int fd = open("c.txt", O_RDWR | O_CREATE | O_TRUNC, 0666 );
    printf("%d\n", fd);
    
    close(fd);
}

// ls -al
//c.txt의 퍼미션은...권한을 지정하지 않으므로 wS-ws등 이상한 쓰래기 값이 들어감
